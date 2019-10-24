#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int from;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int f, int t, lint c = 1) : from(f), to(t), cost(c) {
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
    lint M = LLONG_MAX;
    int n;
    cin >> n;
    vector<vector<lint>> a(n, vector<lint>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<lint>> b(n, vector<lint>(n, M));
    for (int i = 0; i < n; i++) {
        b[i][i] = 0;
    }
    lint ans = 0;
    // i~jに辺を張る必要があるか判定
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                // cout << a[i][j] << " " << a[i][k] << " " << a[k][j] << endl;
                if (a[i][j] == a[i][k] + a[k][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                b[i][j] = a[i][j];
                ans += a[i][j];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    warshall_floyd(b);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i][j] != a[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans / 2 << endl;
}
