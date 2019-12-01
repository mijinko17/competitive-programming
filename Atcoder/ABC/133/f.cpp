#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    int color;
    lint cost;
    //引数一つの時は距離1
    edge(int t, int _color, lint c = 1) : to(t), color(_color), cost(c) {
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
};

void dfs(int f, int n, vector<vector<edge>>& g, vector<int>& c_num,
         vector<lint>& c_sum,
         vector<unordered_map<int, pair<int, lint>>>& memo) {
    for (auto itr = memo[n].begin(); itr != memo[n].end(); itr++) {
        auto now = *itr;
        memo[n][now.first] = {c_num[now.first], c_sum[now.first]};
    }
    for (int i = 0; i < g[n].size(); i++) {
        if (i != f) {
            auto now = g[n][i];
            c_num[now.color]++;
            c_sum[now.color] += now.cost;
            dfs(n, now.to, g, c_num, c_sum, memo);
            c_num[now.color]--;
            c_sum[now.color] -= now.cost;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--;
        g[a].push_back(edge(b, c, d));
        g[b].push_back(edge(a, c, d));
    }
    lowest_common_ancestor lca(g, 0);
    lca.build();
    vector<int> u(q), v(q), x(q), y(q);
    // memo[v][c]={cの個数,cの長さの合計}
    vector<unordered_map<int, pair<int, lint>>> memo;
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i] >> u[i] >> v[i];
        x[i]--, y[i]--, u[i]--, v[i]--;
        memo[u[i]][x[i]] = {0, 0};
        memo[v[i]][x[i]] = {0, 0};
        memo[lca.query(u[i], v[i])][x[i]] = {0, 0};
    }
    vector<int> c_num(n - 1, 0);
    vector<lint> c_sum(n - 1, 0);
    dfs(-1, 1, g, c_num, c_sum, memo);
}
