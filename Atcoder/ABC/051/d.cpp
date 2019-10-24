#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

// warshall_floyd
// dは隣接行列(long long intを使うこと)
void warshall_floyd(vector<vector<long long int>>& d) {
    long long int n = d.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == LLONG_MAX || d[k][j] == LLONG_MAX) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

//ただの辺
struct edge {
    using lint = long long int;
    int from;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int f, int t, lint c = 1) : from(f), to(t), cost(c) {
    }
    edge() {
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<lint>> d(n, vector<lint>(n, LLONG_MAX));
    vector<edge> e(m, edge());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
        e[i] = edge(a, b, c);
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    warshall_floyd(d);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int from = e[i].from, to = e[i].to;
        if (d[from][to] != e[i].cost) {
            ans++;
        }
    }
    cout << ans << endl;
}
