#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//累積和
// vectorっぽく使う
template <typename T>
struct cumulative_sum {
    // data[i]:元の数列
    vector<T> data;
    // sum[i]:[0,i)の和
    vector<long long int> sum;
    //要素数を指定して初期化
    cumulative_sum(const int n) {
        data.assign(n, 0);
    }
    T& operator[](const int k) {
        return data[k];
    }
    // dataに基づいてsumを構築
    void build() {
        sum.assign(data.size() + 1, 0);
        for (int i = 0; i < (int)data.size(); i++) {
            sum[i + 1] = sum[i] + data[i];
        }
    }
    //[a,b)の和を求める
    long long int query(const int a, const int b) {
        return sum[b] - sum[a];
    }
};

int main() {
    lint n, k;
    cin >> n >> k;
    cumulative_sum<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.build();
    vector<lint> b;
    for (int left = 0; left <= n; left++) {
        for (int right = left + 1; right <= n; right++) {
            b.push_back(a.query(left, right));
        }
    }
    lint ans = 0;
    for (int i = 45; i >= 0; i--) {
        // k個のandでiビット目を立てられるか見る
        int num_bit = 0;
        for (int j = 0; j < b.size(); j++) {
            if (b[j] & (1LL << i)) {
                num_bit++;
            }
        }
        if (num_bit >= k) {
            //粛清
            for (int j = 0; j < b.size(); j++) {
                if ((b[j] & (1LL << i)) == 0) {
                    b[j] = 0;
                }
            }
            ans += 1LL << i;
        }
    }
    cout << ans << endl;
}
