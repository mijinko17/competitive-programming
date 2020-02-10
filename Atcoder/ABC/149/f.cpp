#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

lint mod = 1e+9 + 7;
lint n;
vector<lint> p, inv;
vector<vector<edge>> g;
map<pair<int, int>, int> weight;

int dfs(int now, int direction) {
    int res = 1;
    for (auto e : g[direction]) {
        if (e.to == now) continue;
        res += dfs(direction, e.to);
    }
    weight[{now, direction}] = res;
    return res;
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
    // weight辞書を作る
    for (auto e : g[0]) {
        dfs(0, e.to);
    }
    // weightに基づき、cost=(頂点からto方向に何個頂点があるか)を代入
    for (int i = 0; i < n; i++) {
        for (auto &e : g[i]) {
            if (weight[{i, e.to}] > 0) {
                e.cost = weight[{i, e.to}];
            } else {
                e.cost = n - weight[{e.to, i}];
            }
        }
    }
    // 2冪の前計算
    p.resize(n + 1), inv.resize(n + 1);
    p[0] = 1, p[1] = 2, inv[0] = 1, inv[1] = (mod + 1) / 2;
    for (int i = 1; i < n; i++) {
        p[i + 1] = (p[i] * p[1]) % mod;
        inv[i + 1] = (inv[i] * inv[1]) % mod;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        lint temp = p[n - 1] - 1;
        for (auto e : g[i]) {
            temp = (temp - (p[e.cost] - 1)) % mod;
        }
        temp = (temp * inv[n]) % mod;
        ans = (ans + temp) % mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
}
