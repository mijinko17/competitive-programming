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

// 木のlcaをキビキビ計算
// depend:edge
struct lowest_common_ancestor {
    using G = vector<vector<edge>>&;
    G g;
    int sz;
    int root;
    int log;
    vector<int> dep;
    vector<vector<int>> parent;
    lowest_common_ancestor(G _g, int _root)
        : g(_g), sz(_g.size()), root(_root), dep(_g.size()) {
        log = 1;
        while (1 << log < sz) log++;
        parent.assign(log, vector<int>(sz, -1));
    }
    // parent[0]埋め、深さ埋め
    void dfs(int now, int p, int d) {
        parent[0][now] = p;
        dep[now] = d;
        for (int i = 0; i < (int)g[now].size(); i++) {
            int next = g[now][i].to;
            if (next != p) dfs(next, now, d + 1);
        }
    }
    // 前計算を済ませる O(nlog n)
    void build() {
        dfs(root, -1, 0);
        for (int i = 1; i < log; i++) {
            for (int j = 0; j < sz; j++) {
                if (parent[i - 1][j] == -1)
                    parent[i][j] = -1;
                else
                    parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }
    // uとvのlcaを求める O(log sz)
    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = 0; i < log; i++) {
            if ((dep[v] - dep[u]) & (1 << i)) v = parent[i][v];
        }
        if (u == v) return u;
        for (int i = log - 1; i >= 0; i--) {
            if (parent[i][u] != parent[i][v])
                u = parent[i][u], v = parent[i][v];
        }
        return parent[0][u];
    }
    // 頂点の深さ
    int depth(int u) {
        return dep[u];
    }
    // uからnだけ遡る
    int root_back(int u, int n) {
        if (n > (1 << (log - 1))) return -1;
        for (int i = 0; (1 << i) <= n; i++) {
            if ((n >> i) & 1) u = parent[i][u];
        }
        return u;
    }
    // u,v間の距離
    int dist(int u, int v) {
        return depth(u) + depth(v) - 2 * depth(query(u, v));
    }
};

// fromからもっとも遠い頂点(second)とその距離(first)を求める
// depend:edge
pair<long long int, int> tree_farest(vector<vector<edge>>& g, int from,
                                     int par) {
    using lint = long long int;
    pair<lint, int> res = {0, from};
    for (int i = 0; i < (int)g[from].size(); i++) {
        if (g[from][i].to == par) continue;
        pair<lint, int> sub = tree_farest(g, g[from][i].to, from);
        sub.first += g[from][i].cost;
        res = max(res, sub);
    }
    return res;
}

//木の直径
// depend:edge,tree_farest
long long int tree_diameter(vector<vector<edge>>& g) {
    pair<long long int, int> temp = tree_farest(g, 0, -1);
    return tree_farest(g, temp.second, -1).first;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(edge(b));
        g[b].push_back(edge(a));
    }
    auto start = tree_farest(g, 0, -1);
    auto goal = tree_farest(g, start.second, -1);
    lint ans = goal.first;
    lowest_common_ancestor lca(g, start.second);
    lca.build();
    int third;
    lint cand = -1;
    for (int i = 0; i < n; i++) {
        if (i == start.second || i == goal.second) {
            continue;
        }
        int t = lca.query(i, goal.second);
        if (chmax(cand, (lint)lca.dist(i, t))) {
            third = i;
        }
    }
    ans += cand;
    cout << ans << endl;
    cout << start.second + 1 << " " << goal.second + 1 << " " << third + 1
         << endl;
}
