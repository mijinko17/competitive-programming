#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        lint a, b;
        cin >> a >> b;
        if (a == b) {
            cout << (a - 1) * (a - 1) << endl;
            continue;
        }
        if (a > b) {
            swap(a, b);
        }
        lint ans = 0;
        ans += b - 1;
        lint sq = (int)sqrt(a * b - 1);
        ans += sq;
        ans += (sq - 1) - b;
        cout << ans << endl;
    }
}
