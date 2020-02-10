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

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--, v--;
        if (g[v][u] > 0) {
            if (g[v][u] >= d) {
                g[v][u] -= d;
            } else {
                g[u][v] = d - g[v][u];
                g[v][u] = 0;
            }
        }
    }
}
