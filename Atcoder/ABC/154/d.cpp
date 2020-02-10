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

int n, k;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> k;
    cumulative_sum cum(n);
    for (int i = 0; i < n; i++) {
        lint p;
        cin >> p;
        cum[i] = p + 1;
    }
    cum.build();
    lint ans = 0;
    for (int i = 0; i <= n - k; i++) {
        chmax(ans, cum.query(i, i + k));
    }
    cout << setprecision(10) << ((double)ans) / 2 << endl;
}
