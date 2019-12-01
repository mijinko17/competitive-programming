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
    int n,k;
    cin>>n>>k;
    cumulative_sum a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
    }
    a.build();
    if (n+1<k) {
        unordered_map<int, lint> count;
        for (int i = 0; i <=n; i++) {
            count[a.sum[i]%k]++;
        }
        lint ans=0;
        for (auto itr = count.begin(); itr !=count.end(); itr++) {
            auto temp=(*itr).second;
            ans+=temp*(temp-1)/2;
        }
        cout<<ans<<endl;
    }else {
        lint ans=0;
        //first state
        unordered_map<int, lint> count;
        for (int i = 0; i <=k-2; i++) {
            count[a.sum[i]%k]++;
        }
        for (auto itr = count.begin(); itr !=count.end(); itr++) {
            auto temp=(*itr).second;
            ans+=temp*(temp-1)/2;
        }
        cout<<ans<<endl;
        //i:[i-k+2,i]
        for (int i = k-1; i <=n; i++) {
            count[a.sum[i-k+1]%k]--;
            ans+=count[a.sum[i]%k];
            count[a.sum[i]%k]++;
        }
        cout<<ans<<endl;
    }
}
