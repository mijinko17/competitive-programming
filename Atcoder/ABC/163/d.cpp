#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;
lint mod = 1e+9 + 7;

int main() {
    cin >> n >> k;
    lint ans = 0;
    for (lint i = k; i <= n + 1; i++) {
        lint m = i * (i - 1) / 2 % mod;
        lint M = i * (2 * n - i + 1) / 2 % mod;
        lint add = (M - m + 1) % mod;
        ans = (ans + add) % mod;
    }
    if (ans < 0) {
        ans = (ans + mod) % mod;
    }
    cout << ans << endl;
}
