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

int n, m, k;
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

int main() {
    cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }
    cin >> k;
    vector<int> x(k), y(k), z(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i] >> z[i];
        x[i]--, y[i]--;
    }
    g.resize(n * k);
    //同じ頂点間
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            g[i + j * n].push_back(edge(i + (j + 1) * n, 0));
        }
    }
    //普通の辺
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            g[a[j] + n * i].push_back(edge(b[j] + n * i, c[j]));
            g[b[j] + n * i].push_back(edge(a[j] + n * i, c[j]));
        }
    }
    //追加する辺
    for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
            g[x[i] + n * j].push_back(edge(y[i] + n * j, z[i]));
            g[y[i] + n * j].push_back(edge(x[i] + n * j, z[i]));
        }
    }
    vector<lint> ans(k);
    for (int i = 0; i < n; i++) {
        auto d = dijkstra(g, i);
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++) {
                ans[l] += d[j + l * n];
            }
        }
    }
    for (auto e : ans) {
        cout << e / 2 << endl;
    }
}
