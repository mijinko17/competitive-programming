#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

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
    lint &operator[](const int k) {
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

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int n;

int main() {
    cin >> n;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n % 2 == 0) {
        1 / (n % 2);
        lint cand0 = 0, cand1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                cand0 += a[i];
            } else {
                cand1 += a[i];
            }
        }
        cout << max(cand1, cand0) << endl;
        return 0;
    } else {
        cumulative_sum even(n), odd(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even[i] = a[i];
            } else {
                odd[i] = a[i];
            }
        }
        even.build();
        odd.build();
        lint ans = LLONG_MIN;
        lint now = 0;
        for (int i = 0; i < n; i = i + 2) {
            // a[i]を取らない
            chmax(ans, now + even.query(i + 1, n));
            chmax(ans, now + odd.query(i + 1, n));
            // a[i]を取る
            now += a[i];
        }
        cout << ans << endl;
    }
}
