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

// 辺の長さを無視した距離
// depend:edge
vector<int> distance_nonweight(vector<vector<edge>> &g, int start) {
    vector<int> res(g.size(), INT_MAX);
    res[start] = 0;
    queue<int> bfs;
    bfs.push(start);
    while (!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();
        for (auto e : g[now]) {
            int next = e.to;
            if (res[next] > res[now] + 1) {
                res[next] = res[now] + 1;
                bfs.push(next);
            }
        }
    }
    return res;
}

// 木のlcaをキビキビ計算
// depend:edge
struct lowest_common_ancestor {
    using G = vector<vector<edge>> &;
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

bool check(int v, int m, int k, vector<vector<edge>> &g,
           lowest_common_ancestor &lca, vector<int> &d) {
    if (d[v] == INT_MAX) return false;
    int n = g.size();
    vector<int> cand;
    for (int i = 0; i < n; i++) {
        if (lca.query(i, v) == i || d[i] == INT_MAX) continue;
        cand.push_back(d[i]);
    }
    if (cand.size() < m) return false;
    sort(cand.begin(), cand.end());
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += cand[i];
    }
    return sum <= k;
}

void dfs(int v, int p, vector<vector<edge>> &g, vector<int> &d) {
    d[v] = INT_MAX;
    for (auto e : g[v]) {
        int next = e.to;
        if (next != p && d[next] != INT_MAX) dfs(next, v, g, d);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    k -= m;
    if (k < 0) {
        cout << -1 << endl;
        return 0;
    }
    int root;
    vector<int> p(n);
    vector<int> indeg(n, 0);
    vector<vector<edge>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if (p[i] == -1) {
            root = i;
        } else {
            indeg[p[i]]++;
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
        }
    }
    lowest_common_ancestor lca(g, root);
    lca.build();
    vector<int> d = distance_nonweight(g, root);
    queue<int> ans;
    cout << "ok" << endl;
    for (int i = m; i >= 1; i--) {
        int next = -1;
        for (int j = 0; j < n; j++) {
            if (d[j] == INT_MAX) continue;
            if (check(j, i - 1, k - d[j], g, lca, d)) {
                next = j;
                k -= d[j];
                break;
            }
        }
        if (next == -1) {
            cout << -1 << endl;
            return 0;
        }
        dfs(next, lca.parent[0][next], g, d);
        ans.push(next);
    }
    for (int i = 0; i < m; i++) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
}
