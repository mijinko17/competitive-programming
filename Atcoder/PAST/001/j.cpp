#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

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
vector<long long int> dijkstra(vector<vector<edge>> &g, int start) {
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
    lint h, w;
    cin >> h >> w;
    vector<vector<lint>> a(h, vector<lint>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<edge>> g(h * w);
    //(i,j)が辺を貼る
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i - 1 >= 0) {
                g[i * w + j].push_back(edge((i - 1) * w + j, a[i - 1][j]));
            }
            if (i + 1 < h) {
                g[i * w + j].push_back(edge((i + 1) * w + j, a[i + 1][j]));
            }
            if (j - 1 >= 0) {
                g[i * w + j].push_back(edge(i * w + j - 1, a[i][j - 1]));
            }
            if (j + 1 < w) {
                g[i * w + j].push_back(edge(i * w + j + 1, a[i][j + 1]));
            }
        }
    }
    vector<lint> d = dijkstra(g, (h - 1) * w);
    vector<lint> e = dijkstra(g, h * w - 1);
    vector<lint> f = dijkstra(g, w - 1);
    lint ans = LLONG_MAX;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            lint cand =
                d[i * w + j] + e[i * w + j] + f[i * w + j] - 2 * a[i][j];
            chmin(ans, cand);
        }
    }
    cout << ans << endl;
}
