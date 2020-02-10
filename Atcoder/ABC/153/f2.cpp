#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// 遅延セグメント木
// ref:https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
template <typename Monoid, typename OperatorMonoid = Monoid>
struct segment_tree_lazy {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, OperatorMonoid)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
    int sz, height;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e;
    const OperatorMonoid id;
    segment_tree_lazy(int _sz, const F _f, const G _g, const H _h,
                      const Monoid& _e, const OperatorMonoid _id)
        : f(_f), g(_g), h(_h), e(_e), id(_id) {
        sz = 1, height = 0;
        while (sz < _sz) sz <<= 1, height++;
        data.assign(2 * sz, e);
        lazy.assign(2 * sz, id);
    }
    void set(const int k, const Monoid& x) {
        data[k + sz] = x;
    }
    Monoid operator[](const int& k) {
        return query(k, k + 1);
    }
    void build() {
        for (int i = sz - 1; i > 0; i--)
            data[i] = f(data[i * 2], data[i * 2 + 1]);
    }
    Monoid reflect(int k) {
        return lazy[k] == id ? data[k] : g(data[k], lazy[k]);
    }
    void propagate(int k) {
        if (lazy[k] != id) {
            lazy[2 * k] = h(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = id;
        }
    }
    void recalc(int k) {
        while (k >>= 1) data[k] = f(reflect(2 * k), reflect(2 * k + 1));
    }
    // 自分より上にあるやつ全てに対して上から順にpropagate
    void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }
    // [a,b)にxを作用させる
    void update(int a, int b, const OperatorMonoid& x) {
        thrust(a += sz), thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a), recalc(b);
    }
    Monoid query(int a, int b) {
        thrust(a += sz), thrust(b += sz - 1);
        Monoid L = e, R = e;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, reflect(l++));
            if (r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }
};

lint n, d, a;
vector<pair<lint, lint>> xh;

int main() {
    cin >> n >> d >> a;
    xh.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> xh[i].first >> xh[i].second;
    }
    sort(xh.begin(), xh.end());
    vector<lint> x(n);
    auto add = [](const lint a, const lint b) { return a + b; };
    segment_tree_lazy<lint> h(n, add, add, add, 0, 0);
    for (int i = 0; i < n; i++) {
        x[i] = xh[i].first;
        h.set(i, xh[i].second);
    }
    h.build();
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] <= 0) continue;
        lint num = (h[i] + a - 1) / a;
        ans += num;
        int right = upper_bound(x.begin(), x.end(), x[i] + 2 * d) - x.begin();
        h.update(i, right, -num * a);
    }
    cout << ans << endl;
}
