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
vector<vector<lint>> d;

// Warshall_Floyd
// dは隣接行列
template <typename T>
void warshall_floyd(vector<vector<T>> &d) {
    int n = d.size();
    T T_max = numeric_limits<T>::max();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == T_max || d[k][j] == T_max) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    d.assign(n, vector<lint>(n, LLONG_MAX));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        d[a][b] = d[b][a] = c;
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    warshall_floyd(d);
    lint s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s += d[i][j];
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                lint cand = min(d[p][x] + z + d[y][q], d[p][y] + z + d[x][q]);
                if (d[p][q] > cand) {
                    s -= d[p][q] - cand;
                    d[p][q] = cand;
                }
            }
        }
        cout << s / 2 << endl;
    }
}
