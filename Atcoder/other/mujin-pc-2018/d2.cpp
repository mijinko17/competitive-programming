#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;

int rev(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoi(s);
}

pair<int, int> f(pair<int, int> p) {
    if (p.first * p.second == 0) {
        return make_pair(0, 0);
    }
    if (p.first < p.second) {
        p.first = rev(p.first);
    } else {
        p.second = rev(p.second);
    }
    if (p.first < p.second) {
        p.second -= p.first;
    } else {
        p.first -= p.second;
    }
    return p;
}

int p2i(pair<int, int> p) {
    return p.first * 1000 + p.second;
}

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
    cin >> n >> m;
    union_find uf(1000 * 1000);
    for (int i = 0; i <= 999; i++) {
        for (int j = 0; j <= 999; j++) {
            uf.unite(p2i({i, j}), p2i(f({i, j})));
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!uf.isSame(p2i({i, j}), p2i({0, 0}))) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
