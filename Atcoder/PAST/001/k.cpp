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

int main() {
    int n;
    cin >> n;
    int root;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p--;
        if (p < 0) {
            root = i;
        } else {
            g[i].push_back(p);
            g[p].push_back(i);
        }
    }
    lowest_common_ancestor lca(g, root);
    lca.build();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        string ans;
        if (lca.depth(a) < lca.depth(b)) {
            ans = "No";
        } else if (lca.query(a, b) == b) {
            ans = "Yes";
        } else {
            ans = "No";
        }
        cout << ans << endl;
    }
}
