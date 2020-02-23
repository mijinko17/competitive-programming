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
lint n, k;

int main() {
    cin >> n >> k;
    combination_mod comb(2 * n, mod);
    if (k >= n - 1) {
        cout << comb.query(2 * n - 1, n) << endl;
        return 0;
    }
    if (k == 1) {
        cout << n * (n - 1) % mod << endl;
        return 0;
    }
    lint ans = (1 + n * (n - 1)) % mod;
    for (int i = 1; i < k; i++) {
        lint ta = comb.query(n, i + 1);
        ta *= comb.query(n - 1, i + 1);
        ta %= mod;
        ans = (ans + ta) % mod;
    }
    cout << ans << endl;
}
