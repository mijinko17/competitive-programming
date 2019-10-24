#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    //湧き出しかどうか
    vector<bool> spring(n, true);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(edge(y));
        spring[y] = false;
    }
    // 湧き出しからbfsぽくいきたい
    // first:vertex,second:length
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (spring[i]) {
            q.push({i, 0});
        }
    }
    int ans = 0;
    // path[i]:頂点iが終点の有向パスで最長なものの長さ
    vector<int> path(n, 0);
    while (q.size() > 0) {
        int v = q.front().first, l = q.front().second;
        q.pop();
        if (path[v] > l) continue;
        for (int i = 0; i < g[v].size(); i++) {
            if (path[g[v][i].to] >= path[v] + 1) continue;
            path[g[v][i].to] = path[v] + 1;
            ans = max(ans, path[v] + 1);
            q.push({g[v][i].to, path[v] + 1});
        }
    }
    cout << ans << endl;
}
