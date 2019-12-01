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
    //[a,m),[m,b)で切った時の差
    lint cutdiff(const int a, const int b, const int m) {
        return abs(query(m, b) - query(a, m));
    }
};

int main() {
    int n;
    cin >> n;
    cumulative_sum a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.build();
    lint ans = LLONG_MAX;
    // [0,i),[i,n)で切る
    for (int i = 2; i <= n - 2; i++) {
        vector<lint> bcde(4);
        //前半の切り方を決める
        // B-A>0なる[0,ok),[ok,i)で最大のokを探す
        int ok1 = 1, no1 = i;
        while (abs(ok1 - no1) > 1) {
            int mid1 = (ok1 + no1) / 2;
            if (a.query(mid1, i) - a.query(0, mid1) > 0) {
                ok1 = mid1;
            } else {
                no1 = mid1;
            }
        }
        if (ok1 + 1 < i && a.cutdiff(0, i, ok1 + 1) < a.cutdiff(0, i, ok1)) {
            ok1++;
        }
        bcde[0] = a.query(0, ok1);
        bcde[1] = a.query(ok1, i);
        //後半の切り方を決める
        // D-C>0なる[i,ok2),[ok2,n)で最大のokを探す
        int ok2 = i + 1, no2 = n;
        while (abs(ok2 - no2) > 1) {
            int mid2 = (ok2 + no2) / 2;
            if (a.query(mid2, n) - a.query(i, mid2) > 0) {
                ok2 = mid2;
            } else {
                no2 = mid2;
            }
        }
        if (ok2 + 1 < n && a.cutdiff(i, n, ok2 + 1) < a.cutdiff(i, n, ok2)) {
            ok2++;
        }
        bcde[2] = a.query(i, ok2);
        bcde[3] = a.query(ok2, n);
        ans = min(ans, *max_element(all(bcde)) - *min_element(all(bcde)));
    }
    cout << ans << endl;
}
