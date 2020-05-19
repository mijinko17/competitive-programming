#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

int main() {
    cin >> n;
    lint mod = 998244353;
    vector<lint> ans(n + 1, 0);
    ans[n] = 10;
    for (int i = 1; i <= n - 1; i++) {
        if (i < n - 1) {
            ans[i] = pow_mod(10, n - i - 2, mod) * 81 % mod * (n - i - 1) % mod * 10 % mod;
        }
        ans[i] += pow_mod(10, n - i - 1, mod) * 180 % mod;
        ans[i] %= mod;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
