#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
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
    // vectorで要素を指定して初期化
    segment_tree(vector<Mnd> v, function<Mnd(Mnd, Mnd)> f, Mnd a)
        : op(f), e(a) {
        n = 1;
        while (n < (int)v.size()) n *= 2;
        data.assign(n * 2, e);
        for (int i = 0; i < (int)v.size(); i++) {
            *this[i] = v[i];
        }
    }
    //参照渡しなので代入とかもできる
    Mnd& operator[](const int& k) {
        return data[k + n];
    }
    //木を構築 O(n)
    void build() {
        for (int i = n - 1; i > 0; i--) {
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }
    //更新しつつ木を再構築 O(log n)
    void update(int k, Mnd x) {
        *this[k] = x;
        k = (k + n) / 2;
        while (k > 0) {
            data[k] = f(data[2 * k], data[2 * k + 1]);
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

int mymax(int a, int b) {
    return max(a, b);
}

int main() {
    int n;
    cin >> n;
    segment_tree<int> sg(n, mymax, -1);
    for (int i = 0; i < n; i++) {
        cin >> sg[i];
    }
    sg.build();
}
