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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<vector<lint>> d(h * w, vector<lint>(h * w, LLONG_MAX));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                if (i - 1 >= 0)
                    if (s[i - 1][j] == '.') {
                        d[i * w + j][(i - 1) * w + j] = 1;
                    }
                if (i + 1 < h) {
                    if (s[i + 1][j] == '.') {
                        d[i * w + j][(i + 1) * w + j] = 1;
                    }
                }
                if (j - 1 >= 0) {
                    if (s[i][j - 1] == '.') {
                        d[i * w + j][i * w + j - 1] = 1;
                    }
                }
                if (j + 1 < w) {
                    if (s[i][j + 1] == '.') {
                        d[i * w + j][i * w + j + 1] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < h * w; i++) {
        d[i][i] = 0;
    }
    warshall_floyd(d);
    lint ans = 0;
    for (int i = 0; i < h * w; i++) {
        for (int j = 0; j < h * w; j++) {
            if (d[i][j] == LLONG_MAX) {
                continue;
            }
            ans = max(d[i][j], ans);
        }
    }
    cout << ans << endl;
}
