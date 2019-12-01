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
    int n;
    cin >> n;
    cumulative_sum<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a.build();
    unordered_map<lint, lint> count;
    for (int i = 0; i <= n; i++) {
        count[a.sum[i]]++;
    }
    lint ans = 0;
    for (auto itr = count.begin(); itr != count.end(); itr++) {
        lint temp = (*itr).second;
        ans += temp * (temp - 1) / 2;
    }
    cout << ans << endl;
}
