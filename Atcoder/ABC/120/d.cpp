#include <bits/stdc++.h>
using namespace std;

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
    long long int n, m;
    cin >> n >> m;
    vector<pair<int, int>> bridge(m);
    for (int i = 0; i < m; i++) {
        cin >> bridge[i].first >> bridge[i].second;
        bridge[i].first--;
        bridge[i].second--;
    }
    // unconv[i]:i番目の橋が壊れた時の不便さ
    vector<long long int> unconv(m);
    unconv[m - 1] = n * (n - 1) / 2;
    union_find uf(n);
    // i:くっつける橋
    for (int i = m - 1; i > 0; i--) {
        int x = bridge[i].first, y = bridge[i].second;
        if (!uf.isSame(x, y)) {
            unconv[i - 1] = unconv[i] - uf.size(x) * uf.size(y);
            uf.unite(x, y);
        } else {
            unconv[i - 1] = unconv[i];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << unconv[i] << endl;
    }
}
