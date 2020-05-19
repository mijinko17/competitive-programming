#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// AGC-033-C

// ただの辺
struct edge {
    int to;
    long long cost;
    // 引数一つの時は距離1
    edge(int t, long long c = 1) : to(t), cost(c) {}
};

int n;
vector<vector<edge>> g;

// s[i]:iの部分木の深さ
vector<int> s;
vector<int> ans;

void dfs1(int now, int par) {
    int res = 0;
    for (auto e : g[now]) {
        if (e.to == par) continue;
        dfs1(e.to, now);
        res = max(res, s[e.to]) + e.cost;
    }
    s[now] = res;
}

void dfs2(int now, int par, int rev) {}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    s.resize(n);
    ans.resize(n);
}
