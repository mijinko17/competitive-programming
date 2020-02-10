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

int n;
vector<int> a, b;

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

template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int o = n / 2;
    lint ans = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        //ビット立つ:oddでの採用
        bitset<18> bit(i);
        int count = 0;
        for (int j = 0; j < n; j++) {
            count += bit[j];
        }
        if (count != o) continue;
        vector<pair<int, int>> odd_part, even_part;
        for (int j = 0; j < n; j++) {
            if (bit[j]) {
                int val = (j % 2 == 1 ? a[j] : b[j]);
                odd_part.push_back({val, j});
            } else {
                int val = (j % 2 == 0 ? a[j] : b[j]);
                even_part.push_back({val, j});
            }
        }
        stable_sort(odd_part.begin(), odd_part.end());
        stable_sort(even_part.begin(), even_part.end());
        vector<int> fusion_val(n), fusion_index(n);
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                fusion_val[j] = even_part[j / 2].first;
                fusion_index[j] = even_part[j / 2].second;
            } else {
                fusion_val[j] = odd_part[j / 2].first;
                fusion_index[j] = odd_part[j / 2].second;
            }
        }
        bool flag = true;
        for (int j = 0; j < n - 1; j++) {
            if (fusion_val[j] > fusion_val[j + 1]) {
                flag = false;
            }
        }
        if (!flag) {
            continue;
        }
        lint cand = inversion_number(fusion_index);
        chmin(ans, cand);
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
