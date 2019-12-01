#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// ABC-137-E

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

// Bellman-Ford
// depend:edge
// 到達不可能:LLONG_MAX、負閉路を経由可能:LLONG_MIN
vector<lint> bellman_ford(vector<vector<edge>>& g, int s) {
    int n = g.size();
    vector<long long int> res(n, LLONG_MAX);
    res[s] = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[j] == LLONG_MAX) continue;
            for (int k = 0; k < (int)g[j].size(); k++) {
                int c = g[j][k].cost, dest = g[j][k].to;
                if (i < n - 1) {
                    res[dest] = min(res[dest], res[j] + c);
                } else {
                    if (res[j] == LLONG_MIN || res[dest] > res[j] + c)
                        res[dest] = LLONG_MIN;
                }
            }
        }
    }
    return res;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].push_back(edge(b, p - c));
    }
    vector<lint> dist = bellman_ford(g, 0);
    if (dist[n - 1] == LLONG_MIN) {
        cout << -1 << endl;
    } else {
        cout << max(-dist[n - 1], 0LL) << endl;
    }
}
