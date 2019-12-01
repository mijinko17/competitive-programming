#include <bits/stdc++.h>
#include <vector>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    long double cost;
    //引数一つの時は距離1
    edge(int t, long double c = 1) : to(t), cost(c) {
    }
};

// dijkstra
// depend:edge
vector<long double> dijkstra(vector<vector<edge>>& g, int start) {
    vector<long double> res(g.size(), FLT_MAX);
    res[start] = 0;
    // first:距離、second:行き先
    priority_queue<pair<long double, lint>, vector<pair<long double, lint>>,
                   greater<pair<long double, lint>>>
        pq;
    pq.push({0, start});
    while (!pq.empty()) {
        long double dist = pq.top().first;
        int now = pq.top().second;
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
    int xs, ys, xt, yt, n;
    cin >> xs >> ys >> xt >> yt >> n;
    vector<int> x(n + 2), y(n + 2), r(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        x[i]--, y[i]--;
    }
    x[n] = xs, x[n + 1] = xt;
    y[n] = ys, y[n + 1] = yt;
    r[n] = 0, r[n + 1] = 0;
    vector<vector<edge>> g(n + 2);
    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            long double xd = x[i] - x[j], yd = y[i] - y[j];
            long double dist = sqrt(xd * xd + yd * yd) - r[i] - r[j];
            g[i].push_back(edge(j, max((long double)0, dist)));
            g[j].push_back(edge(i, max((long double)0, dist)));
        }
    }
    vector<long double> dist = dijkstra(g, n);
    cout << dist[n + 1] << endl;
}
