#include <bits/stdc++.h>
typedef long long lint;
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

int n, m, k;

int main() {
    cin >> n >> m >> k;
    vector<int> num_friends(n, 0);
    union_find uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b);
        num_friends[a]++;
        num_friends[b]++;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = uf.size(i) - 1;
        ans[i] -= num_friends[i];
    }
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        if (uf.isSame(c, d)) {
            ans[c]--, ans[d]--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
