#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans = 0;
    // eの方のジャケット
    for (int i = 0; i <= d; i++) {
        int s = min({a, i});
        int t = min({b, c, d - i});
        ans = max(s * e + t * f, ans);
    }
    cout << ans << endl;
}
