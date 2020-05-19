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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto dist = distance_nonweight(g, 0);
    vector<int> ans(n);
    for (int i = 1; i < n; i++) {
        for (auto e : g[i]) {
            if (dist[i] == dist[e.to] + 1) {
                ans[i] = e.to;
                break;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; i++) {
        cout << ans[i] + 1 << endl;
    }
}
