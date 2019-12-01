#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
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
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(3 * n);
    for (int i = 0; i < m; i++) {
        int v, w;
        cin >> v >> w;
        v--, w--;
        g[v].push_back(edge(w + n));
        g[v + n].push_back(edge(w + 2 * n));
        g[v + 2 * n].push_back(edge(w));
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    vector<lint> dist = dijkstra(g, s);
    if (dist[t] == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[t] / 3 << endl;
    }
}
