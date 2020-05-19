#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ただの辺
struct edge {
    int to;
    long long cost;
    // 引数一つの時は距離1
    edge(int t, long long c = 1) : to(t), cost(c) {}
};

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

// Z_pでのaの逆元を計算 O(log p)
// depend:pow_mod
long long inv_mod(long long a, long long p) {
    return pow_mod(a, p - 2, p);
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

int n;
const lint mod = 1e+9 + 7;
vector<vector<edge>> g;
vector<lint> base;
vector<lint> num;
vector<lint> ans;
combination_mod comb(300000, mod);

void dfs1(int now, int par) {
    int res = 1;
    for (auto e : g[now]) {
        if (e.to == par) continue;
        dfs1(e.to, now);
        res += num[e.to];
    }
    num[now] = res;
}

void dfs2(int now, int par) {
    lint res = 1;
    int rem = num[now] - 1;
    for (auto e : g[now]) {
        if (e.to == par) {
            continue;
        }
        dfs2(e.to, now);
        res = res * base[e.to] % mod * comb.query(rem, num[e.to]) % mod;
        rem -= num[e.to];
    }
    base[now] = res;
}

void dfs3(int now, int par, lint rev) {
    lint res = rev * comb.fac[n - 1] % mod * comb.finv[n - num[now]] % mod;
    for (auto e : g[now]) {
        if (e.to == par) continue;
        res = res * comb.finv[num[e.to]] % mod * base[e.to] % mod;
    }
    ans[now] = res;
    res = res * comb.finv[n - 1] % mod;
    for (auto e : g[now]) {
        if (e.to == par) continue;
        lint next_rev = res * comb.fac[n - num[e.to] - 1] % mod * inv_mod(base[e.to], mod) % mod *
                        comb.fac[num[e.to]] % mod;
        dfs3(e.to, now, next_rev);
    }
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    base.resize(n);
    num.resize(n);
    ans.resize(n);
    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1, 1);
    for (auto e : ans) {
        cout << e << endl;
    }
}
