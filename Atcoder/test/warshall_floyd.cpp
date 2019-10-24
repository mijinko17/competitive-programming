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

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    lint M = LLONG_MAX;
    vector<vector<lint>> d(n, vector<lint>(n, M));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    warshall_floyd(d);
    vector<vector<lint>> e(n, vector<lint>(n, M));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] <= l) {
                e[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        e[i][i] = 0;
    }
    warshall_floyd(e);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        if (e[s][t] == M) {
            cout << -1 << endl;
        } else {
            cout << e[s][t] - 1 << endl;
        }
    }
}
