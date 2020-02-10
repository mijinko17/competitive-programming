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

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int n;
int a[200000];
int d[2][200000];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<edge>> g(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) g[i - a[i]].push_back(i);
        if (i + a[i] < n) g[i + a[i]].push_back(i);
    }
    // d[i][j]:jの偶奇iのやつまでの距離
    vector<vector<int>> d(2, vector<int>(n, INT_MAX));
    for (int i = 0; i < 2; i++) {
        queue<pair<int, int>> bfs;
        for (int j = 0; j < n; j++) {
            if ((a[j] - i) % 2 == 0) bfs.push({j, 1});
        }
        while (!bfs.empty()) {
            int now = bfs.front().first, dist = bfs.front().second;
            bfs.pop();
            for (auto e : g[now]) {
                if (chmin(d[i][e.to], dist)) bfs.push({e.to, dist + 1});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int ans = d[(a[i] + 1) % 2][i];
        if (ans == INT_MAX) ans = -1;
        cout << ans << " ";
    }
    cout << endl;
}
