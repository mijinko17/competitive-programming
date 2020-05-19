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
vector<vector<int>> dp;
vector<int> ans;

int lis() {
    int ok = n, no = -1;
    while (abs(ok - no) > 1) {
        int m = (ok + no) / 2;
        if (dp[m].back() == INT_MAX) {
            ok = m;
        } else {
            no = m;
        }
    }
    return ok;
}

int insert_index(int x) {
    int ok = n - 1, no = -1;
    while (abs(ok - no) > 1) {
        int m = (ok + no) / 2;
        if (dp[m].back() >= x) {
            ok = m;
        } else {
            no = m;
        }
    }
    return ok;
}

void dfs(int now, int from) {
    int target = insert_index(a[now]);
    dp[target].push_back(a[now]);
    ans[now] = lis();
    for (auto e : g[now]) {
        if (e.to == from) {
            continue;
        }
        dfs(e.to, now);
    }
    dp[target].pop_back();
}

int main() {
    cin >> n;
    a.resize(n);
    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // dp[i].back:長さi+1の最長部分列の最小
    dp.resize(n, vector<int>(1, INT_MAX));
    ans.resize(n);
    dfs(0, -1);
    for (auto e : ans) {
        cout << e << endl;
    }
}
