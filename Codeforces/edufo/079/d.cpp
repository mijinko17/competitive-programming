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
    vector<lint> inv;
    combination_mod(int _sz, lint _mod) : sz(_sz), mod(_mod) {
        fac.assign(sz + 1, 1);
        finv.assign(sz + 1, 1);
        inv.assign(sz + 1, 1);
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
    lint mod = 998244353;
    combination_mod comb(1e+6, mod);
    vector<lint> inv = comb.inv;
    vector<lint> prob_y(1e+6, 0);
    vector<lint> num_wanted(1e+6, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            a--;
            prob_y[a] += (inv[n] * inv[k]) % mod;
            prob_y[a] %= mod;
            num_wanted[a]++;
        }
    }
    lint ans = 0;
    for (int i = 0; i < 1e+6; i++) {
        lint temp = (prob_y[i] * num_wanted[i]) % mod;
        temp = (temp * inv[n]) % mod;
        ans = (ans + temp) % mod;
    }
    cout << ans << endl;
}
