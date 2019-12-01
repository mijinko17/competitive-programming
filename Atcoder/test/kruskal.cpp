#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// ABC-065-D

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

//素集合データ構造
// ref:https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct union_find {
    // parent[v]==w(>=0):vの親はw
    // parent[v]==k(<0):vは根&&vの属するグループの要素数は-k
    vector<long long int> parent;
    // dimH_0:グループ数
    long long int dimH_0;
    //コンストラクタ
    union_find(long long int n) : dimH_0(n) {
        parent.assign(n, -1);
    }
    // vの根を求める
    //求めると同時に親を根に置き換える(木の圧縮)
    long long int root(long long int v) {
        if (parent[v] < 0) {
            return v;
        } else {
            parent[v] = root(parent[v]);
            return parent[v];
        }
    }
    // vが属するグループの要素数を求める
    long long int size(long long int v) {
        return -parent[root(v)];
    }
    // vとwを繋げる
    void unite(long long int v, long long int w) {
        v = root(v), w = root(w);
        if (v == w) return;
        if (parent[v] < parent[w]) swap(v, w);
        parent[w] += parent[v];
        parent[v] = w;
        dimH_0--;
    }
    // vとwが同値か判定
    bool isSame(long long int v, long long int w) {
        return root(v) == root(w);
    }
};

long long int kruskal(vector<vector<edge>> &g) {
    using lint = long long int;
    int n = g.size();
    lint res = 0;
    priority_queue<pair<lint, pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g.size(); j++) {
            pq.push(make_pair(g[i][j].cost, make_pair(i, g[i][j].to)));
        }
    }
    union_find uf(n);
    while (uf.dimH_0 > 1) {
        auto c = pq.top().first;
        auto e = pq.top().second;
        pq.pop();
        if (!uf.isSame(e.first, e.second)) {
            uf.unite(e.first, e.second);
            res += c;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    // first:座標、second:添字
    vector<pair<int, int>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> y[i].first;
        x[i].second = i, y[i].second = i;
    }
    sort(all(x));
    sort(all(y));
    vector<vector<edge>> g(n);
    for (int i = 0; i < n; i++) {
        g[x[i].second].push_back(
            edge(x[i + 1].second, x[i + 1].first - x[i].first));
        g[x[i + 1].second].push_back(
            edge(x[i].second, x[i + 1].first - x[i].first));
    }
    for (int i = 0; i < n; i++) {
        g[y[i].second].push_back(
            edge(y[i + 1].second, y[i + 1].first - y[i].first));
        g[y[i + 1].second].push_back(
            edge(y[i].second, y[i + 1].first - y[i].first));
    }
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j].to << " ";
        }
        cout << endl;
    }
    cout << kruskal(g) << endl;
}
