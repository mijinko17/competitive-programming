#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// nCr mod p(n<p)をキビキビ計算する
// 構築:O(n), クエリ:O(1)
struct combination_mod {
    using lint = long long int;
    int sz;
    lint mod;
    vector<lint> fac;
    vector<lint> finv;
    combination_mod(int _sz, lint _mod) : sz(_sz), mod(_mod) {
        fac.assign(sz + 1, 1);
        finv.assign(sz + 1, 1);
        vector<lint> inv(sz + 1, 1);
        for (int i = 2; i <= sz; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint query(int n, int r) {
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
};

lint mod = 1e+9 + 7;
lint n, a, b;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

int main() {
    cin >> n >> a >> b;
    combination_mod comb(max(a, b), mod);
    lint fac_a = 1;
    for (int i = n; i > n - a; i--) {
        fac_a = fac_a * i % mod;
    }
    lint fac_b = 1;
    for (int i = n; i > n - b; i--) {
        fac_b = fac_b * i % mod;
    }
    lint ans = pow_mod(2, n, mod) - 1;
    ans -= fac_a * comb.finv[a] % mod;
    ans %= mod;
    ans -= fac_b * comb.finv[b] % mod;
    ans %= mod;
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
}
