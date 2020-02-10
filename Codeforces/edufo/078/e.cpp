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

void dfs(int from, int now, int coord, int right, vector<vector<edge>>& g) {
}

struct info {
    int v;
    int left;
    int from;
    info(int _v, int _left, int _from) : v(_v), left(_left), from(_from) {
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<pair<int, int>> seg(n);
    int end = 1;
    stack<info> dfs;
    dfs.push(info(0, 0, -1));
    while (!dfs.empty()) {
        auto now = dfs.top();
        dfs.pop();
        seg[now.v] = {now.left, end + g[now.v].size() - 1};
        int offset = 1;
        for (auto e : g[now.v]) {
            if (e.to == now.from) continue;
            dfs.push(info(e.to, now.left + offset, now.v));
            offset++;
        }
    }
}
