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

//素集合データ構造
// ref:https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct union_find {
    // parent[v]==w(>=0):vの親はw
    // parent[v]==k(<0):vは根&&vの属するグループの要素数は-k
    vector<long long int> parent;
    //コンストラクタ
    union_find(long long int n) {
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
        v = root(v);
        w = root(w);
        if (v == w) return;
        if (parent[v] < parent[w]) swap(v, w);
        parent[w] += parent[v];
        parent[v] = w;
    }
    // vとwが同値か判定
    bool isSame(long long int v, long long int w) {
        return root(v) == root(w);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n), z(n), a(m), b(m), c(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vector<vector<edge>> base(n + m);
    //大大
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            lint cost = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if (z[i] != z[j]) {
                cost *= 10;
            }
            base[i].push_back(edge(j, cost));
            base[j].push_back(edge(i, cost));
        }
    }
    //小小
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
        }
    }
    for (int i = 0; i < (1 << m); i++) {
        vector<vector<edge>> g = base;
        bitset<5> bit = i;
        //小さいやつ同士貼る
        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                lint cost;
                if (bit[j] == 1 && bit[k] == 1) {
                    cost = abs(a[j] - a[k]) + abs(b[j] - b[k]);
                    if (c[j] != c[k]) {
                        cost *= 10;
                    }
                } else {
                    cost = INT_MAX;
                }
                g[n + j].push_back(edge(n + k, cost));
                g[n + k].push_back(edge(n + j, cost));
            }
        }
        //大小で貼る
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                lint cost;
                if (bit[k]) {
                }
            }
        }
    }
}
