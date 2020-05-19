#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint x;
    cin >> x;
    lint now = 100;
    lint ans = 0;
    while (1) {
        ans += 1;
        now += now / 100;
        if (now >= x) {
            cout << ans << endl;
            return 0;
        }
    }
}
