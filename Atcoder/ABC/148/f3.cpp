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

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n, u, v;
    cin >> n >> u >> v;
    u--, v--;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> du = distance_nonweight(g, u);
    vector<int> dv = distance_nonweight(g, v);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].size() > 1 || du[i] >= dv[i]) continue;
        chmax(ans, dv[i] - 1);
    }
    cout << ans << endl;
}
