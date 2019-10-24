#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    edge(lint t, lint c) : to(t), cost(c) {
    }
};
// dijkstra
vector<long long int> dijkstra(vector<vector<edge>> g, int start) {
    using lint = long long int;
    int n = g.size();
    vector<lint> res(n, LLONG_MAX);
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
