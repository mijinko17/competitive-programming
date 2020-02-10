#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n != 1) res[n]++;
    return res;
}

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
    lint mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    combination_mod comb(n + 32, mod);
    unordered_map<int, int> count = pf_um(m);
    lint ans = 1;
    for (auto e : count) {
        int k = e.second;
        ans = (ans * comb.query(n - 1 + k, k)) % mod;
    }
    cout << ans << endl;
}
