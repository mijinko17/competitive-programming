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

//[i,s)でのクエリがq未満なる最小のi
//なければ0
int find_left(segment_tree<int> seg, int s, int q) {
    int ok = s, ng = -1;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (seg.query(mid, s) < q) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}
//[s+1,i+1)でのクエリがq未満なる最大のi
//なければn
int find_right(segment_tree<int> seg, int s, int q, int n) {
    int ok = s, ng = n;
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (seg.query(s + 1, mid + 1) < q) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n;
    cin >> n;
    segment_tree<int> p(
        n, [](int a, int b) { return max(a, b); }, INT_MIN);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    p.build();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // l2<l1<r1<r2の順序
        int l1, l2, r1, r2;
        l1 = find_left(p, i, p[i]);
        l2 = find_left(p, l1, p[i]);
        // l2 = l1 != 0 ? find_left(p, l1, p[i]) : 0;
        r1 = find_right(p, i, p[i], n);
        r2 = find_right(p, r1, p[i], n);
        cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
        ans += ((r1 - l2 + 1) + (r2 - l1 + 1)) * p[i];
    }
    cout << ans << endl;
}
