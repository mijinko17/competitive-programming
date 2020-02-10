#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//素集合データ構造
// ref:https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct union_find {
    // parent[v]==w(>=0):vの親はw
    // parent[v]==k(<0):vは根&&vの属するグループの要素数は-k
    vector<long long int> parent;
    int dimH_0;
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
        v = root(v);
        w = root(w);
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

int main() {
    int n;
    cin >> n;
    union_find password(26);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 1; j < s[i].length(); j++) {
            password.unite(s[i][0] - 'a', s[i][j] - 'a');
        }
    }
    unordered_set<int> count;
    for (int i = 0; i < n; i++) {
        count.insert(password.root(s[i][0] - 'a'));
    }
    cout << count.size() << endl;
}
