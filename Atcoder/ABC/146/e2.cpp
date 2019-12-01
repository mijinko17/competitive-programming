#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
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
    int n, k;
    cin >> n >> k;
    cumulative_sum a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    a.build();
    for (int i = 0; i < a.sum.size(); i++) {
        a.sum[i] %= k;
    }
    auto s = a.sum;
    lint ans = 0;
    unordered_map<int, lint> count;
    //区間を[l,r)で管理
    int l = 0, r = 0;
    while (r + 1 <= n + 1) {
        r++;
        if (r - l > k) {
            count[s[l]]--;
            l++;
        }
        ans += count[s[r - 1]];
        count[s[r - 1]]++;
    }
    cout << ans << endl;
}
