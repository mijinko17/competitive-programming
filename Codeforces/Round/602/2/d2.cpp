#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct query {
    int index;
    int k;
    int pos;
    int ans;
    query() {
    }
    query(int i, int _k, int p, int a = 0) : index(i), k(_k), pos(p), ans(a) {
    }
};

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
    // [0,x)でのクエリがk以上の最小のx
    int find(Mnd k) {
        Mnd ok = sz, no = 0;
        while (abs(ok - no) > 1) {
            Mnd mid = (ok + no) / 2;
            if (query(0, mid) >= k) {
                ok = mid;
            } else {
                no = mid;
            }
        }
        return ok;
    }
};

int main() {
    int n;
    cin >> n;
    // first:value,second:index
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    auto b = a;
    int m;
    cin >> m;
    vector<query> q(m);
    for (int i = 0; i < m; i++) {
        int k, pos;
        cin >> k >> pos;
        q[i] = query(i, k, pos);
    }
    sort(
        a.begin(), a.end(), [](const pair<int, int> x, const pair<int, int> y) {
            return x.first == y.first ? x.second < y.second : x.first > y.first;
        });
    sort(q.begin(), q.end(),
         [](const query x, const query y) { return x.k < y.k; });
    segment_tree<int> seg(
        n, [](int x, int y) { return x + y; }, 0);
    // segtreeに[0,now_k)までぶち込んでると考える
    int now_k = 0;
    for (int i = 0; i < m; i++) {
        while (now_k < q[i].k) {
            seg.update(a[now_k].second, 1);
            now_k++;
        }
        q[i].ans = b[seg.find(q[i].pos) - 1].first;
    }
    sort(q.begin(), q.end(),
         [](const query x, const query y) { return x.index < y.index; });
    for (int i = 0; i < m; i++) {
        cout << q[i].ans << endl;
    }
}
