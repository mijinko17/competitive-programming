#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
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
    int x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = (x + y) / 3;
    x -= n, y -= n;
    if (x < 0 || y < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << combination_mod(n, 1e+9 + 7).query(n, x) << endl;
}
