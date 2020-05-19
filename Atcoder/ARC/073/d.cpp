#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// 累積和
struct cumulative_sum {
    using lint = long long;
    int sz;
    // data[i]:元の数列
    vector<lint> data;
    // cum[i]:[0,i)の和
    vector<lint> sum;
    // 要素数を指定して初期化
    cumulative_sum(const int _sz = 0) : sz(_sz) {
        data.assign(sz, 0);
        sum.assign(sz + 1, 0);
    }
    lint &operator[](const int k) {
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

int n, w;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> w;
    vector<vector<lint>> goods(4);
    lint w_0, v_0;
    cin >> w_0 >> v_0;
    goods[0].push_back(v_0);
    for (int i = 1; i < n; i++) {
        int s, t;
        cin >> s >> t;
        goods[s - w_0].push_back(t);
    }
    for (int i = 0; i < 4; i++) {
        sort(goods[i].begin(), goods[i].end(), greater<lint>());
    }
    vector<cumulative_sum> cum(4);
    for (int i = 0; i < 4; i++) {
        cum[i] = cumulative_sum(goods[i].size());
        for (int j = 0; j < goods[i].size(); j++) {
            cum[i][j] = goods[i][j];
        }
        cum[i].build();
    }
    lint ans = 0;
    for (int i = 0; i <= cum[0].sz; i++) {
        for (int j = 0; j <= cum[1].sz; j++) {
            for (int k = 0; k <= cum[2].sz; k++) {
                for (int l = 0; l <= cum[3].sz; l++) {
                    if (i * w_0 + j * (w_0 + 1) + k * (w_0 + 2) + l * (w_0 + 3) <= w) {
                        lint cand = cum[0].query(0, i) + cum[1].query(0, j) + cum[2].query(0, k) +
                                    cum[3].query(0, l);
                        chmax(ans, cand);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
