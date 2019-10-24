#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//累積和
struct cumulative_sum {
    // data[i]:[0,i)の和
    vector<long long int> data;
    //コンストラクタ O(n)
    template <typename T>
    cumulative_sum(vector<T>& v) {
        data.assign(v.size() + 1, 0);
        for (int i = 0; i < (int)v.size(); i++) {
            data[i + 1] = data[i] + v[i];
        }
    }
    //[a,b)の和を求める
    long long int sum(long long int a, long long int b) {
        return data[b] - data[a];
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    // a:そのまま、b:満足セット
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = max(a[i], 0);
    }
    cumulative_sum cum_a(a), cum_b(b);
    // i:諦める区間の左端
    lint ans = 0;
    for (int i = 0; i <= n - k; i++) {
        lint candidate = cum_b.sum(0, i) + max((lint)0, cum_a.sum(i, i + k)) +
                         cum_b.sum(i + k, n);
        ans = max(ans, candidate);
    }
    cout << ans << endl;
}
