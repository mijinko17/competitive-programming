#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ただの辺
struct edge {
    int to;
    long long cost;
    int index;
    // 引数一つの時は距離1
    edge(int t, long long c = 1, int i = 0) : to(t), cost(c), index(i) {}
};

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int c, d;
        cin >> c >> d;
        // first:順番、second:index
        vector<int> x(c, 0);
        vector<pair<int, int>> y(c, {0, 0});
        for (int i = 1; i < c; i++) {
            cin >> x[i];
            x[i] *= -1;
            y[i].first = x[i];
            y[i].second = i;
        }
        sort(y.begin(), y.end());
        vector<vector<edge>> g(c);
        for (int i = 0; i < d; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(edge(v, 1e+6, i));
            g[v].push_back(edge(u, 1e+6, i));
        }
        vector<int> dist(c, INT_MAX);
        dist[0] = 0;
        for (int i = 1; i < c; i++) {
            for (auto &e : g[y[i].second]) {
                if (dist[e.to] == INT_MAX) {
                    continue;
                }
                if (y[i].first == x[e.to]) {
                    continue;
                }
                e.cost = y[i].first - dist[e.to];
                dist[y[i].second] = y[i].first;
                break;
            }
        }
        vector<lint> ans(d, INT_MAX);
        for (int i = 0; i < c; i++) {
            for (auto e : g[i]) {
                chmin(ans[e.index], e.cost);
            }
        }
        for (auto e : ans) {
            cout << e << ' ';
        }
        cout << endl;
    }
    return 0;
}
