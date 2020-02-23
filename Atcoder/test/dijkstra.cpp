#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    edge(lint t, lint c) : to(t), cost(c) {}
};

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

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<vector<edge>> go(n), back(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        go[a].push_back(edge(b, c));
        back[b].push_back(edge(a, c));
    }
    vector<lint> d_go = dijkstra(go, 0), d_back = dijkstra(back, 0);
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (d_go[i] == LLONG_MAX || d_back[i] == LLONG_MAX) continue;
        ans = max(ans, (t - d_go[i] - d_back[i]) * A[i]);
    }
    cout << ans << endl;
}
