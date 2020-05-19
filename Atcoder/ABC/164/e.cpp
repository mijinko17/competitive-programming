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

vector<vector<edge>> g;

// dijkstra
// depend:edge
vector<long long> dijkstra(vector<vector<edge>> g, int start) {
    using P = pair<long long, long long>;
    vector<long long> res(g.size(), LLONG_MAX);
    res[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;  // first:距離、second:行き先
    pq.push({0, start});
    while (!pq.empty()) {
        long long dist = pq.top().first, now = pq.top().second;
        pq.pop();
        if (res[now] < dist) continue;
        for (auto e : g[now]) {
            if (res[e.to] <= res[now] + e.cost) continue;
            res[e.to] = res[now] + e.cost;
            pq.push(make_pair(res[e.to], e.to));
        }
    }
    return res;
}

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    g.resize(n * 2501);
    for (int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        // j:出発の所持金
        for (int j = 0; j <= 2500; j++) {
            if (j - a >= 0) {
                g[2501 * u + j].push_back(edge(2501 * v + j - a, b));
                g[2501 * v + j].push_back(edge(2501 * u + j - a, b));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        // j:出発の所持金
        for (int j = 0; j <= 2500; j++) {
            g[2501 * i + j].push_back(edge(2501 * i + min(2500, j + c), d));
        }
    }
    auto dist = dijkstra(g, min(2500, s));
    for (int i = 1; i < n; i++) {
        lint ans = LLONG_MAX;
        for (int j = 0; j <= 2500; j++) {
            chmin(ans, dist[2501 * i + j]);
        }
        cout << ans << endl;
    }
}
