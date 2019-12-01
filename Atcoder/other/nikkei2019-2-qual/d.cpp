#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<lint, lint>, lint>> lrc(m);
    for (int i = 0; i < m; i++) {
        cin >> lrc[i].first.first >> lrc[i].first.second >> lrc[i].second;
        lrc[i].first.first--, lrc[i].first.second--;
    }
    sort(all(lrc));
    segment_tree_lazy<lint> dist(
        n, [](lint a, lint b) { return min(a, b); },
        [](lint a, lint b) { return min(a, b); },
        [](lint a, lint b) { return min(a, b); }, LLONG_MAX, LLONG_MAX);
    dist.update(0, 1, 0);
    for (int i = 0; i < m; i++) {
        auto now = lrc[i];
        lint x = now.first.first, y = now.first.second, c = now.second;
        lint temp = dist.query(x, y);
        if (temp == LLONG_MAX) continue;
        dist.update(x, y + 1, temp + c);
    }
    lint ans = dist[n - 1];
    if (dist[n - 1] == LLONG_MAX) {
        ans = -1;
    }
    cout << ans << endl;
}
