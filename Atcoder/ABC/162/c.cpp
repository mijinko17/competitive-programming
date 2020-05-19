#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint ggcd(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

int main() {
    lint n;
    cin >> n;
    lint ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ans += ggcd(i, j, k);
            }
        }
    }
    cout << ans << endl;
}
