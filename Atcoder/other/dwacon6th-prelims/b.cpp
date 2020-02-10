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
    int n;
    cin >> n;
    vector<lint> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    combination_mod comb(n + 1, mod);
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            lint temp = x[j] - x[i];
            temp = (temp * comb.query(n - 1, j - i + 1)) % mod;
            temp = (temp * comb.fac[j - i - 1]) % mod;
            temp = (temp * comb.fac[n - 2 - j + i]) % mod;
            ans += temp;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        lint temp = x[n - 1] - x[i];
        temp = (temp * comb.query(n - 1, n - i - 1)) % mod;
        temp = (temp * comb.fac[n - i - 2]) % mod;
        temp = (temp * comb.fac[i]) % mod;
        ans += temp;
    }
    cout << ans << endl;
}
