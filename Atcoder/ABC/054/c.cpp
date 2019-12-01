#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
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

// nowスタートでまだ行ってないところを全部回る行き方
int dfs(int now, int arrived, vector<vector<edge>>& g) {
    if (arrived == (1 << g.size()) - 1) {
        return 1;
    } else {
        int res = 0;
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i].to;
            if ((arrived & (1 << next)) == 0) {
                res += dfs(next, arrived | (1 << next), g);
            }
        }
        return res;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(edge(b));
        g[b].push_back(edge(a));
    }
    cout << dfs(0, 1, g) << endl;
}
