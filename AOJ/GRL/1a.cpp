#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

// dijkstra
// depend:edge
vector<long long int> dijkstra(vector<vector<edge>>& g, int start) {
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
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(edge(t, d));
    }
    vector<lint> dist = dijkstra(g, r);
    for (int i = 0; i < n; i++) {
        if (dist[i] == LLONG_MAX) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
