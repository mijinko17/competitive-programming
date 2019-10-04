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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> city(n);
    for (int i = 0; i < n; i++) {
        cin >> city[i].second.first >> city[i].second.second;
        city[i].first = i;
    }
    vector<pair<int, pair<int, int>>> edges;
    union_find uf(n);
    // x成分でソート
    sort(city.begin(), city.end(),
         [](const pair<int, pair<int, int>> x,
            const pair<int, pair<int, int>> y) {
             return x.second.first < y.second.first;
         });
    for (int i = 0; i < n - 1; i++) {
        pair<int, pair<int, int>> c1 = city[i];
        pair<int, pair<int, int>> c2 = city[i + 1];
        edges.push_back(make_pair(c2.second.first - c1.second.first,
                                  make_pair(c1.first, c2.first)));
    }
    // y成分でソート
    sort(city.begin(), city.end(),
         [](const pair<int, pair<int, int>> x,
            const pair<int, pair<int, int>> y) {
             return x.second.second < y.second.second;
         });
    for (int i = 0; i < n - 1; i++) {
        pair<int, pair<int, int>> c1 = city[i];
        pair<int, pair<int, int>> c2 = city[i + 1];
        edges.push_back(make_pair(c2.second.second - c1.second.second,
                                  make_pair(c1.first, c2.first)));
    }
    sort(edges.begin(), edges.end(),
         [](const pair<int, pair<int, int>> x,
            const pair<int, pair<int, int>> y) { return x.first < y.first; });
    //最小全域木の計算
    int connected = 1;
    int ans = 0;
    auto itr = edges.begin();
    while (connected < n && itr != edges.end()) {
        if (!uf.isSame((*itr).second.first, (*itr).second.second)) {
            ans += (*itr).first;
            uf.unite((*itr).second.first, (*itr).second.second);
            connected++;
        }
        itr++;
    }
    cout << ans << endl;
}
