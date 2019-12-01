#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
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
    int n, k, l;
    cin >> n >> k >> l;
    union_find road(n), train(n), rt(n);
    for (int i = 0; i < k; i++) {
        int p, q;
        cin >> p >> q;
        p--, q--;
        road.unite(p, q);
    }
    for (int i = 0; i < l; i++) {
        int r, s;
        cin >> r >> s;
        r--, s--;
        train.unite(r, s);
        if (road.isSame(r, s)) rt.unite(r, s);
    }
    for (int i = 0; i < n; i++) {
        cout << rt.size(i) << endl;
    }
}
