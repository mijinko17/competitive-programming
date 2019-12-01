#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

// ABC-106-D

//二次元累積和
struct cumulative_sum_2d {
    using lint = long long int;
    int sz;
    vector<vector<lint>> data;
    vector<vector<lint>> sum;
    cumulative_sum_2d(const int _sz) : sz(_sz) {
        data.assign(sz, vector<lint>(sz));
        sum.assign(sz + 1, vector<lint>(sz + 1));
    }
    vector<lint>& operator[](const int k) {
        return data[k];
    }
    void build() {
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                sum[i + 1][j + 1] =
                    sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + data[i][j];
    }
    //[a,b)×[c,d)の和を計算
    lint query(const int a, const int b, const int c, const int d) const {
        return sum[b][d] - sum[b][c] - sum[a][d] + sum[a][c];
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    cumulative_sum_2d cum(n);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cum[l][r]++;
    }
    cum.build();
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << cum.query(x, y + 1, x, y + 1) << endl;
    }
}
