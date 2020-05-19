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

// 辺の長さを無視した距離
// depend:edge
vector<int> distance_nonweight(vector<vector<edge>> &g, int start) {
    vector<int> res(g.size(), INT_MAX);
    res[start] = 0;
    queue<int> bfs;
    bfs.push(start);
    while (!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();
        for (auto e : g[now]) {
            int next = e.to;
            if (res[next] > res[now] + 1) {
                res[next] = res[now] + 1;
                bfs.push(next);
            }
        }
    }
    return res;
}

int p2i(int x, int y) {
    return x * 1000 + y;
}

inline pair<int, int> operate(int x, int y) {
    string s;
    if (x < y) {
        s = to_string(x);
        reverse(s.begin(), s.end());
        x = stoi(s);
    } else {
        s = to_string(y);
        reverse(s.begin(), s.end());
        y = stoi(s);
    }
    int z = abs(x - y);
    if (x < y) {
        y = z;
    } else {
        x = z;
    }
    return make_pair(x, y);
}

int n, m;

int main() {
    cin >> n >> m;
    vector<vector<edge>> g(1000 * 1000);
    for (int i = 1; i < 1000; i++) {
        g[0].push_back(p2i(i, 0));
        g[0].push_back(p2i(0, i));
    }
    for (int i = 1; i < 1000; i++) {
        for (int j = 1; j < 1000; j++) {
            auto next = operate(i, j);
            g[p2i(next.first, next.second)].push_back(p2i(i, j));
        }
    }
    auto dist = distance_nonweight(g, 0);
    lint ans = n * m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dist[p2i(i, j)] != INT_MAX) {
                ans--;
            }
        }
    }
    cout << ans << endl;
}
