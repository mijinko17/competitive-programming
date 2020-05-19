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

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        segment_tree<int> b_max(
            n, [](int x, int y) { return max(x, y); }, INT_MIN);
        segment_tree<int> b_min(
            n, [](int x, int y) { return min(x, y); }, INT_MAX);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b_min[i] = b_max[i] = a[i];
        }
        b_max.build();
        b_min.build();
        bool flag = true;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == b[i]) {
                continue;
            } else if (b[i] > a[i]) {
                if (b_max.query(0, i) <= 0) {
                    flag = false;
                    break;
                }
            } else {
                if (b_min.query(0, i) >= 0) {
                    flag = false;
                    break;
                }
            }
        }
        if (a[0] != b[0]) {
            flag = false;
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
