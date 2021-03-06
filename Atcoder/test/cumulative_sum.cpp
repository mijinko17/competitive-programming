#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
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
    int n, t;
    cin >> n >> t;
    t++;
    cumulative_sum cum(t);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cum[l]++, cum[r]--;
    }
    cum.build();
    int ans = 0;
    for (int i = 0; i < t + 1; i++) {
        ans = max((lint)ans, cum.query(0, i));
    }
    cout << ans << endl;
}
