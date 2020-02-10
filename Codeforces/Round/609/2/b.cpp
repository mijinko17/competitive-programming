#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, m;
    cin >> n >> m;
    vector<lint> a(n), b(n);
    unordered_map<lint, lint> ca, cb;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ca[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cb[b[i]]++;
    }
    lint ans = LLONG_MAX;
    // a[0]とb[i]を一致させたい
    for (int i = 0; i < n; i++) {
        bool flag = true;
        lint x = (b[i] - a[0] + m) % m;
        for (int j = 0; j < n; j++) {
            if (ca[a[j]] != cb[(a[j] + x) % m]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = min(ans, x);
        }
    }
    cout << ans << endl;
}
