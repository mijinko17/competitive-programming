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
    vector<int> key(m, 0);
    vector<lint> val(m);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s >> val[i];
        for (int j = 0; j < n; j++) {
            if (s[j] == 'Y') {
                key[i] += (1 << j);
            }
        }
    }
    vector<vector<edge>> g((1 << n));
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            g[i].push_back(edge((i | key[j]), val[j]));
        }
    }
    vector<lint> d = dijkstra(g, 0);
    lint ans;
    if (d[(1 << n) - 1] == LLONG_MAX) {
        ans = -1;
    } else {
        ans = d[(1 << n) - 1];
    }
    cout << ans << endl;
}
