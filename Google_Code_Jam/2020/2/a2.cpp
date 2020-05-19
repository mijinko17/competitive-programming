#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        lint l, r;
        cin >> l >> r;
        lint ans = 0;
        while (1) {
            if (max(l, r) < ans + 1) {
                break;
            }
            if (l >= r) {
                ans++;
                l -= ans;
            } else {
                ans++;
                r -= ans;
            }
        }
        cout << ans << ' ' << l << ' ' << r << endl;
    }
    return 0;
}
