#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, d, a;
vector<pair<lint, lint>> xh;

int main() {
    cin >> n >> d >> a;
    xh.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> xh[i].first >> xh[i].second;
    }
    sort(xh.begin(), xh.end());
    vector<lint> x(n), h(n);
    for (int i = 0; i < n; i++) {
        x[i] = xh[i].first, h[i] = xh[i].second;
    }
    // right[i]:[i,right[i])を攻撃できる
    vector<lint> right(n);
    for (int i = 0; i < n; i++) {
        right[i] = upper_bound(x.begin(), x.end(), x[i] + 2 * d) - x.begin();
    }
    vector<lint> damage(n, 0);
    lint dmg_now = 0;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        dmg_now -= damage[i];
        if (h[i] - dmg_now <= 0) {
            continue;
        } else {
            lint rem = h[i] - dmg_now;
            lint num = (rem + a - 1) / a;
            dmg_now += num * a;
            if (right[i] < n) {
                damage[right[i]] += num * a;
            }
            ans += num;
        }
    }
    cout << ans << endl;
}
