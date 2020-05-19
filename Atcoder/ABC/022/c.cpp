#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
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

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    d.assign(n, vector<lint>(n, LLONG_MAX));
    vector<pair<int, lint>> relay_points;
    for (int i = 0; i < m; i++) {
        int u, v;
        lint l;
        cin >> u >> v >> l;
        u--, v--;
        if (u > v) swap(u, v);
        if (u == 0) {
            relay_points.push_back({v, l});
        } else {
            d[u][v] = l;
            d[v][u] = l;
        }
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    warshall_floyd(d);
    lint ans = LLONG_MAX;
    for (int i = 0; i < relay_points.size(); i++) {
        for (int j = i + 1; j < relay_points.size(); j++) {
            int start = relay_points[i].first, goal = relay_points[j].first;
            if (d[start][goal] == LLONG_MAX) continue;
            lint end = relay_points[i].second + relay_points[j].second;
            chmin(ans, d[start][goal] + end);
        }
    }
    if (ans == LLONG_MAX) ans = -1;
    cout << ans << endl;
}
