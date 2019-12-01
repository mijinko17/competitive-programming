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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    //[i][j]を[i*w+j]と思う
    union_find uf(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //上
            if (i != 0 && s[i][j] != s[i - 1][j]) {
                uf.unite(i * w + j, (i - 1) * w + j);
            }
            //下
            if (i != h - 1 && s[i][j] != s[i + 1][j]) {
                uf.unite(i * w + j, (i + 1) * w + j);
            }
            //左
            if (j != 0 && s[i][j] != s[i][j - 1]) {
                uf.unite(i * w + j, i * w + j - 1);
            }
            //右
            if (j != w - 1 && s[i][j] != s[i][j + 1]) {
                uf.unite(i * w + j, i * w + j + 1);
            }
        }
    }
    //各グループとそのグループが含む黒の数を管理
    unordered_map<int, int> gr_black;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                gr_black[uf.root(i * w + j)]++;
            }
        }
    }
    lint ans = 0;
    for (auto itr = gr_black.begin(); itr != gr_black.end(); itr++) {
        ans += (*itr).second * (uf.size((*itr).first) - (*itr).second);
    }
    cout << ans << endl;
}
