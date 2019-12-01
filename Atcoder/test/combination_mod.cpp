#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// AGC-025-B

// nCr mod p(n<p)をキビキビ計算する
// 構築:O(n), クエリ:O(1)
struct combination_mod {
    using lint = long long int;
    int sz;
    lint mod;
    vector<lint> fac;
    vector<lint> finv;
    combination_mod(int _sz, int _mod) : sz(_sz), mod(_mod) {
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
    lint mod = 998244353;
    lint n, a, b, k;
    cin >> n >> a >> b >> k;
    combination_mod cm(n, mod);
    lint ans = 0;
    // Aでi箇所塗る
    for (int i = 0; i <= n; i++) {
        // m:Bの数
        lint rem = k - a * i;
        lint m = rem / b;
        if (rem < 0 || rem % b != 0 || m > n) continue;
        lint temp = cm.query(n, i) * cm.query(n, m);
        temp %= mod;
        ans += temp;
        ans %= mod;
    }
    cout << ans << endl;
}
