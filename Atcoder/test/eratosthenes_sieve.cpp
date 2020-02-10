#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ABC-084-D

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

int q;

//エラトステネスの篩
vector<bool> eratosthenes_sieve(int n) {
    vector<bool> res(n + 1, true);
    res[0] = res[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (res[i]) {
            for (int j = i; i * j <= n; j++) res[i * j] = false;
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<bool> p = eratosthenes_sieve(1e+5);
    cumulative_sum cum(1e+5 + 1);
    for (int i = 0; i <= 1e+5; i++) {
        if (i % 2 == 1 && p[i] && p[(i + 1) / 2]) {
            cum[i] = 1;
        } else {
            cum[i] = 0;
        }
    }
    cum.build();
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        r++;
        cout << cum.query(l, r) << endl;
    }
}
