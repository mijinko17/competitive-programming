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

int main() {
    lint mod = 1e+9 + 7;
    int n, k;
    cin >> n >> k;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    combination_mod comb(n, mod);
    lint ans = 0;
    // min
    for (int i = 0; i <= n - k; i++) {
        lint temp = a[i];
        temp = (a[i] * comb.query(n - i - 1, k - 1)) % mod;
        ans = (ans - temp) % mod;
    }
    // max
    for (int i = k - 1; i < n; i++) {
        lint temp = a[i];
        temp = (a[i] * comb.query(i, k - 1)) % mod;
        ans = (ans + temp) % mod;
    }
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
}
