#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint k;
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

int main() {
    k = 1000000;
    segment_tree<double> seg(
        k, [](double a, double b) { return min(a, b); }, (double)INT_MAX);
    for (int i = 1; i <= k; i++) {
        string s = to_string(i);
        lint snuke = 0;
        for (auto e : s) {
            snuke += e - '0';
        }
        seg[i - 1] = 1.0 * i / snuke;
    }
    seg.build();
    for (int i = 0; i < k; i++) {
        if (seg[i] <= seg.query(i + 1, k)) {
            cout << i + 1 << endl;
        }
    }
}
