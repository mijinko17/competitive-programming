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

int n;
vector<int> a;
vector<vector<edge>> g;
vector<int> dp;
vector<int> ans;

void dfs(int now, int from) {
    int target = lower_bound(dp.begin(), dp.end(), a[now]) - dp.begin();
    int prev = dp[target];
    dp[target] = a[now];
    ans[now] = lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    for (auto e : g[now]) {
        if (e.to == from) {
            continue;
        }
        dfs(e.to, now);
    }
    dp[target] = prev;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp.resize(n, INT_MAX);
    ans.resize(n);
    dfs(0, -1);
    for (auto e : ans) {
        cout << e << endl;
    }
}
