#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// ARC-075-E

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

// 各項の順序を保ったまま最小値0,最大値size()-1以下にする
template <typename T>
vector<T> simplify(vector<T>& a) {
    int n = a.size();
    vector<T> b = a;
    sort(b.begin(), b.end());
    vector<T> res(n);
    for (int i = 0; i < n; i++)
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    return res;
}
// 転倒数を計算
// depend:segment_tree
template <typename T>
long long inversion_number(vector<T>& a) {
    using lint = long long int;
    int n = a.size();
    vector<T> b = simplify(a);
    segment_tree<lint> count(
        n, [](lint a, lint b) { return a + b; }, 0);
    lint res = 0;
    for (int i = 0; i < n; i++) {
        res += count.query(b[i] + 1, n);
        count.update(b[i], count[b[i]] + 1);
    }
    return res;
}

// 累積和
struct cumulative_sum {
    using lint = long long int;
    int sz;
    // data[i]:元の数列
    vector<lint> data;
    // cum[i]:[0,i)の和
    vector<lint> sum;
    // 要素数を指定して初期化
    cumulative_sum(const int _sz) : sz(_sz) {
        data.assign(sz, 0);
        sum.assign(sz + 1, 0);
    }
    lint& operator[](const int k) {
        return data[k];
    }
    // dataに基づいてsumを構築
    void build() {
        for (int i = 0; i < sz; i++) sum[i + 1] = sum[i] + data[i];
    }
    // [a,b)の和を求める
    lint query(const int a, const int b) {
        return sum[b] - sum[a];
    }
};

int main() {
    lint n, k;
    cin >> n >> k;
    cumulative_sum a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
    }
    a.build();
    cout << n * (n + 1) / 2 - inversion_number(a.sum) << endl;
}
