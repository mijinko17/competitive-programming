#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ARC-089-D

// 二次元累積和
struct cumulative_sum_2d {
    using lint = long long;
    int x, y;
    vector<vector<lint>> data;
    vector<vector<lint>> sum;
    cumulative_sum_2d(const int _x, const int _y) : x(_x), y(_y) {
        data.assign(x, vector<lint>(y, 0));
        sum.assign(x + 1, vector<lint>(y + 1, 0));
    }
    vector<lint> &operator[](const int k) {
        return data[k];
    }
    void build() {
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + data[i][j];
    }
    //[a,b)×[c,d)の和を計算
    lint query(const int a, const int b, const int c, const int d) const {
        return sum[b][d] - sum[b][c] - sum[a][d] + sum[a][c];
    }
};

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int n, k;

int main() {
    cin >> n >> k;
    cumulative_sum_2d black(2 * k, 2 * k);
    for (int i = 0; i < n; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'W') {
            y += k;
        }
        x %= 2 * k, y %= 2 * k;
        black[x][y]++;
    }
    black.build();
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int b_ok = black.query(0, i, 0, j) + black.query(i + k, 2 * k, 0, j) +
                       black.query(i, i + k, j, j + k) + black.query(0, i, j + k, 2 * k) +
                       black.query(i + k, 2 * k, j + k, 2 * k);
            chmax(ans, max(b_ok, n - b_ok));
        }
    }
    cout << ans << endl;
}
