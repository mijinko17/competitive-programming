#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// セグメント木
// ref:https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template <typename Mnd>
struct segment_tree {
    int sz;
    vector<Mnd> data;
    function<Mnd(Mnd, Mnd)> f;
    Mnd e;
    //サイズだけ指定して初期化
    segment_tree(int _sz, function<Mnd(Mnd, Mnd)> _f, Mnd _e) : f(_f), e(_e) {
        sz = 1;
        while (sz < _sz) sz <<= 1;
        data.assign(sz * 2, e);
    }
    //参照渡しなので代入とかもできる
    Mnd& operator[](const int& k) {
        return data[k + sz];
    }
    //木を構築 O(n)
    void build() {
        for (int i = sz - 1; i > 0; i--) data[i] = f(data[2 * i], data[2 * i + 1]);
    }
    //更新しつつ木を再構築 O(log n)
    void update(int k, Mnd x) {
        data[k += sz] = x;
        while (k >>= 1) data[k] = f(data[2 * k], data[2 * k + 1]);
    }
    //[a,b)でのクエリに答える　O(log n)
    Mnd query(int a, int b) const {
        Mnd l = e, r = e;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) l = f(l, data[a++]);
            if (b & 1) r = f(r, data[--b]);
        }
        return f(l, r);
    }
};

int n, q;
string s;

int main() {
    cin >> n >> s >> q;
    segment_tree<bitset<26>> seg(
        n, [](const bitset<26> a, const bitset<26> b) { return a | b; }, 0);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        seg[i] = (1 << c);
    }
    seg.build();
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;
            x--;
            int keta = c - 'a';
            seg.update(x, 1 << keta);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.query(l, r).count() << endl;
        }
    }
}
