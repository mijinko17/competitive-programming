#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// warshall_floyd
// dは隣接行列(long long intを使うこと)
void warshall_floyd(vector<vector<long long int>> &d) {
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

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> r(s);
    for (int i = 0; i < s; i++) {
        cin >> r[i];
        r[i]--;
    }
    vector<vector<lint>> d(n, vector<lint>(n, LLONG_MAX));
    for (int i = 0; i < m; i++) {
        lint a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        chmin(d[a][b], c);
        chmin(d[b][a], c);
    }
    for (int i = 0; i < n; i++) d[i][i] = 0;
    warshall_floyd(d);
    vector<int> perm(s);
    for (int i = 0; i < s; i++) perm[i] = i;
    lint ans = LLONG_MAX;
    while (1) {
        lint cand = 0;
        for (int i = 0; i < s - 1; i++) cand += d[r[perm[i]]][r[perm[i + 1]]];
        chmin(ans, cand);
        if (!next_permutation(perm.begin(), perm.end())) break;
    }
    cout << ans << endl;
}
