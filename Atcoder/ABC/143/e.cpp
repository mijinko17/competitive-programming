#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint M = LLONG_MAX;
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<lint>> d(n, vector<lint>(n, M));
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[--a][--b] = c;
        d[b][a] = c;
    }
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if (d[i][k] == M || d[k][j] == M) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    vector<vector<lint>> e(n, vector<lint>(n, M));
    for (int i = 0; i < n; i++) {
        e[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (d[i][j] <= l) {
                e[i][j] = 1;
                e[j][i] = 1;
            }
        }
    }
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                if (e[i][k] == M || e[k][j] == M) continue;
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, t;
        cin >> s >> t;
        if (e[--s][--t] == M) {
            cout << -1 << endl;
        } else {
            cout << e[s][t] - 1 << endl;
        }
    }
}
