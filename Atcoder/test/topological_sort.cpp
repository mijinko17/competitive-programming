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

// トポロジカルソート　O(V+E)
// depend:edge
// 失敗した場合res[0]=-1
vector<int> tolological_sort(vector<vector<edge>>& g) {
    int n = g.size();
    vector<int> res;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)g[i].size(); j++) {
            indeg[g[i][j].to]++;
        }
    }
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) s.push(i);
    }
    while (!s.empty()) {
        int now = s.top();
        s.pop();
        res.push_back(now);
        for (int i = 0; i < (int)g[now].size(); i++) {
            indeg[g[now][i].to]--;
            if (indeg[g[now][i].to] == 0) s.push(g[now][i].to);
        }
    }
    //失敗時の処理
    if ((int)res.size() < n) {
        // vectorが空かもしれないので適当に入れる
        res.push_back(-1);
        res[0] = -1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n), indeg(n);
    for (int i = 0; i < n - 1 + m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(edge(b));
        indeg[b].push_back(edge(a));
    }
    vector<int> topo = tolological_sort(g);
    // topo_order[i]:頂点iがトポロジカルソートの何番目に現れるか
    vector<int> topo_order(n);
    for (int i = 0; i < n; i++) {
        topo_order[topo[i]] = i;
    }
    //初期値用にオーダー-1の頂点nを追加しておく
    topo_order.push_back(-1);
    vector<int> ans(n, n);
    //オーダーが一番若いやつが根
    //最後の処理の都合で-1
    ans[topo[0]] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < indeg[i].size(); j++) {
            if (topo_order[indeg[i][j].to] > topo_order[ans[i]]) {
                ans[i] = indeg[i][j].to;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << endl;
    }
}
