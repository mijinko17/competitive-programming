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
    int n;
    cin >> n;
    cumulative_sum cum(n);
    for (int i = 0; i < n; i++) {
        cin >> cum[i];
    }
    cum.build();
    map<lint, lint> count;
    int right = 0;
    lint ans = 0;
    for (int left = 0; left <= n; left++) {
        while (right <= n && count[cum.sum[right]] == 0) {
            count[cum.sum[right]]++;
            right++;
        }
        ans += right - left - 1;
        if (left == right) {
            right++;
        } else {
            count[cum.sum[left]]--;
        }
    }
    cout << ans << endl;
}
