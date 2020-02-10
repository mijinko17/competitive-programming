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

int n, x;
vector<int> h;
vector<vector<edge>> g;

int dfs(int now, int par) {
    int res = 0;
    for (auto e : g[now]) {
        if (e.to == par) continue;
        int temp = dfs(e.to, now);
        if (h[e.to] == 1 || temp > 0) {
            res += 2 + temp;
        }
    }
    return res;
}

int main() {
    cin >> n >> x;
    x--;
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << dfs(x, -1) << endl;
}
