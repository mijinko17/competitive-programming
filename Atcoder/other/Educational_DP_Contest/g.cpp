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

// path[start]を計算して格納する
void dfs(int start, vector<vector<edge>> &g, vector<int> &path,
         vector<bool> &calced) {
    if (calced[start]) {
        return;
    }
    if (g[start].size() == 0) {
        path[start] = 0;
    } else {
        int temp = 0;
        for (int i = 0; i < g[start].size(); i++) {
            dfs(g[start][i].to, g, path, calced);
            temp = max(temp, path[g[start][i].to]);
        }
        path[start] = temp + 1;
    }
    calced[start] = true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(edge(y));
    }
    // path[i]:iスタートのパスで最長なものの長さ
    vector<int> path(n);
    vector<bool> calced(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dfs(i, g, path, calced);
        ans = max(ans, path[i]);
    }
    cout << ans << endl;
}
