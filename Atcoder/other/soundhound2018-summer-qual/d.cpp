#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
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

// dijkstra
// depend:edge
vector<long long int> dijkstra(vector<vector<edge>>& g, int start) {
    using lint = long long int;
    vector<lint> res(g.size(), LLONG_MAX);
    res[start] = 0;
    // first:距離、second:行き先
    priority_queue<pair<lint, lint>, vector<pair<lint, lint>>,
                   greater<pair<lint, lint>>>
        pq;
    pq.push({0, start});
    while (!pq.empty()) {
        lint dist = pq.top().first, now = pq.top().second;
        pq.pop();
        if (res[now] < dist) continue;
        for (int i = 0; i < (int)g[now].size(); i++) {
            edge e = g[now][i];
            if (res[e.to] > res[now] + e.cost) {
                res[e.to] = res[now] + e.cost;
                pq.push(make_pair(res[e.to], e.to));
            }
        }
    }
    return res;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<edge>> g_yen(n), g_snuuk(n);
    for (int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        g_yen[u].push_back(edge(v, a));
        g_yen[v].push_back(edge(u, a));
        g_snuuk[u].push_back(edge(v, b));
        g_snuuk[v].push_back(edge(u, b));
    }
    vector<lint> d_s = dijkstra(g_yen, s), d_t = dijkstra(g_snuuk, t);
    // loss[i]:[i,n)の街で両替する時の使用金額の最小値
    vector<lint> loss(n + 1);
    loss[n] = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
        loss[i] = min(loss[i + 1], d_s[i] + d_t[i]);
    }
    for (int i = 0; i < n; i++) {
        cout << (lint)1e+15 - loss[i] << endl;
    }
}
