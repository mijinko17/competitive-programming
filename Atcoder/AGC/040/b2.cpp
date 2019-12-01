#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<lint, lint>> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
    }
    sort(all(q));
    for (int i = 0; i < n; i++) {
    }
    //[0,i)での左端の最大値,右端の最小値
    vector<lint> left1(n), right1(n);
    left1[0] = 0;
    right1[0] = 1e+9;
    // lint left1 = 0, left2 = 0, right1 = 1e+9, right2 = 1e+9;
    for (int i = 1; i < n; i++) {
        left1[i] = max(left1[i - 1], q[i - 1].first);
        right1[i] = min(right1[i - 1], q[i - 1].second);
    }
    //[i,n)での左端の最大値,右端の最小値
    vector<lint> left2(n + 1), right2(n + 1);
    left2[n] = 0;
    right2[n] = 1e+9;
    for (int i = n - 1; i >= 1; i--) {
        left2[i] = max(left2[i + 1], q[i].first);
        right2[i] = min(right2[i + 1], q[i].second);
    }
    lint ans = 0;
    for (int i = 1; i < n; i++) {
        lint a = max(right1[i] - left1[i] + 1, 0LL);
        lint b = max(right2[i] - left2[i] + 1, 0LL);
        ans = max(ans, a + b);
    }
    cout << ans << endl;
}
