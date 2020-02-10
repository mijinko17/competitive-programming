#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, m;
vector<lint> a;

//幸福度k以上の握手が何個あるか
lint count(lint k) {
    lint res = 0;
    for (int i = 0; i < n; i++) {
        res += a.end() - lower_bound(a.begin(), a.end(), k - a[i]);
    }
    return res;
}

bool check(lint k) {
    return count(k) < m;
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
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    lint ok = 1e+6, no = 0;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    lint ans = 0;
    ans += (ok - 1) * (m - count(ok));
    cumulative_sum cum(n);
    for (int i = 0; i < n; i++) {
        cum[i] = a[i];
    }
    cum.build();
    for (int i = 0; i < n; i++) {
        int b = lower_bound(a.begin(), a.end(), ok - a[i]) - a.begin();
        ans += a[i] * (n - b) + cum.query(b, n);
    }
    cout << ans << endl;
}
