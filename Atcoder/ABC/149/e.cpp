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

// めぐる式二分探索
long long meguru_BinarySearch(long long ok, long long no,
                              function<bool(long long)> isValid) {
    while (abs(ok - no) > 1) {
        long long mid = (ok >> 1) + (no >> 1) + (1 & ok & no);
        (isValid(mid) ? ok : no) = mid;
    }
    return ok;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    lint ok = meguru_BinarySearch(1e+6, 0, check);
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
