#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//セグメント木
// ref:https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template <typename Mnd>
struct segment_tree {
    int n;
    vector<Mnd> data;
    function<Mnd(Mnd, Mnd)> op;
    Mnd e;
    //サイズだけ指定して初期化
    segment_tree(int sz, function<Mnd(Mnd, Mnd)> f, Mnd a) : op(f), e(a) {
        n = 1;
        while (n < sz) n *= 2;
        data.assign(n * 2, e);
    }
    //参照渡しなので代入とかもできる
    Mnd& operator[](const int& k) {
        return data[k + n];
    }
    //木を構築 O(n)
    void build() {
        for (int i = n - 1; i > 0; i--)
            data[i] = op(data[2 * i], data[2 * i + 1]);
    }
    //更新しつつ木を再構築 O(log n)
    void update(int k, Mnd x) {
        (*this)[k] = x;
        k += n;
        while (k >>= 1) {
            data[k] = op(data[2 * k], data[2 * k + 1]);
        }
    }
    //[a,b)でのクエリに答える　O(log n)
    Mnd query(int a, int b) const {
        Mnd l = e, r = e;
        for (a += n, b += n; a < b; a /= 2, b /= 2) {
            if (a % 2 == 1) l = op(l, data[a++]);
            if (b % 2 == 1) r = op(r, data[--b]);
        }
        return op(l, r);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    segment_tree<int> seg(
        n, [](int a, int b) { return min(a, b); }, INT_MAX);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com) {
            cout << seg.query(x, y + 1) << endl;
        } else {
            seg.update(x, y);
        }
    }
}
