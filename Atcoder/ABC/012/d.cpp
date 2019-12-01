#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
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
    int n, m;
    cin >> n >> m;
    vector<vector<lint>> dist(n, vector<lint>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    warshall_floyd(dist);
    lint ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, *max_element(all(dist[i])));
    }
    cout << ans << endl;
}
