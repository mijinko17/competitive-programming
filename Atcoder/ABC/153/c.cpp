#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    vector<lint> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    if (k >= n) {
        cout << 0 << endl;
        return 0;
    } else {
        sort(h.begin(), h.end());
        lint ans = 0;
        for (int i = 0; i < n - k; i++) {
            ans += h[i];
        }
        cout << ans << endl;
        return 0;
    }
}
