#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// a^n mod pを計算　O(log n)
long long int pow_mod(long long int a, long long int n, long long int p) {
    if (n == 0) return 1;
    long long int temp = pow_mod(a, n / 2, p);
    return n & 1 ? (((temp * temp) % p) * a) % p : (temp * temp) % p;
}

// Z_pでのaの逆元を計算 O(log p)
// depend:pow_mod
long long int inv_mod(long long int a, long long int p) {
    return pow_mod(a, p - 2, p);
}

// 階乗テーブルを作ってコンビネーションをキビキビ計算する
// depend:inv_mod
struct combination_mod {
    using lint = long long int;
    int sz;
    vector<lint> data;
    lint mod;
    combination_mod(int _sz, lint _mod) : sz(_sz), mod(_mod) {
        data.assign(sz + 1, 1);
        for (int i = 1; i <= sz; i++) data[i] = (data[i - 1] * i) % mod;
    }
    // nCrを計算 O(log mod)
    lint query(int n, int r) {
        lint res = 1;
        res = (res * data[n]) % mod;
        res = (res * inv_mod(data[r], mod)) % mod;
        res = (res * inv_mod(data[n - r], mod)) % mod;
        return res;
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
