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

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;
        segment_tree<int> a(
            n, [](int a, int b) { return max(a, b); }, INT_MIN);
        for (int i = 0; i < n; i++) cin >> a[i];
        a.build();
        int m;
        cin >> m;
        // s[i]:体力i以上の最大のパワー
        vector<int> power(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int tp, ts;
            cin >> tp >> ts;
            chmax(power[ts], tp);
        }
        for (int i = n - 1; i >= 0; i--) chmax(power[i], power[i + 1]);
        //進行度を、倒してない最前のモンスターのインデックスで表す
        int now = 0;
        int ans = 0;
        while (now < n) {
            int ok = 0, no = n - now + 1;
            while (abs(ok - no) > 1) {
                int mid = (ok + no) / 2;
                int max_monster = a.query(now, now + mid);
                if (max_monster <= power[mid]) {
                    ok = mid;
                } else {
                    no = mid;
                }
            }
            if (ok == 0) {
                ans = -1;
                break;
            }
            ans++;
            now += ok;
        }
        cout << ans << endl;
    }
}
