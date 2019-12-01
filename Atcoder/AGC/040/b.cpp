#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//セグメント木
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
        for (int i = sz - 1; i > 0; i--)
            data[i] = f(data[2 * i], data[2 * i + 1]);
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
    int n;
    cin >> n;
    vector<pair<int, int>> q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i].first >> q[i].second;
    }
    sort(all(q));
    segment_tree<int> l(
        n, [](lint a, lint b) { return max(a, b); }, INT_MIN);
    segment_tree<int> r(
        n, [](lint a, lint b) { return min(a, b); }, INT_MAX);
    for (int i = 0; i < n; i++) {
        l[i] = q[i].first;
        r[i] = q[i].second;
    }
    l.build(), r.build();
    lint ans = 0;
    if (r[n - 1] == r.query(0, n)) {
        int longest = 0;
        for (int i = 0; i < n; i++) {
            longest = max(longest, q[i].second - q[i].first + 1);
        }
        ans = longest + r[n - 1] - l[n - 1] + 1;
    } else {
        //[0,i),[i,n)で切る
        for (int i = 1; i < n; i++) {
            lint c1 = max(r.query(0, i) - l.query(0, i) + 1, 0);
            lint c2 = max(r.query(i, n) - l.query(i, n) + 1, 0);
            ans = max(ans, c1 + c2);
        }
    }
    cout << ans << endl;
}
