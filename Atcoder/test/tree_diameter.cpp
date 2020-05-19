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

// fromからもっとも遠い頂点(second)とその距離(first)を求める
// depend:edge
pair<long long int, int> tree_farest(vector<vector<edge>>& g, int from,
                                     int par) {
    using lint = long long int;
    pair<lint, int> res = {0, from};
    for (int i = 0; i < (int)g[from].size(); i++) {
        if (g[from][i].to == par) continue;
        pair<lint, int> sub = tree_farest(g, g[from][i].to, from);
        sub.first += g[from][i].cost;
        res = max(res, sub);
    }
    return res;
}

//木の直径
// depend:edge,tree_farest
long long int tree_diameter(vector<vector<edge>>& g) {
    pair<long long int, int> temp = tree_farest(g, 0, -1);
    return tree_farest(g, temp.second, -1).first;
}

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(edge(--b));
        g[b].push_back(edge(a));
    }
    lint d = tree_diameter(g);
    if (d % 3 == 1) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}
