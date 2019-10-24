#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//二次元累積和
struct cumulative_sum_2d {
    vector<vector<long long int>> data;
    //コンストラクタ
    template <typename T>
    cumulative_sum_2d(vector<vector<T>> &v) {
        data = vector<vector<long long int>>(
            v.size() + 1, vector<long long int>(v[0].size() + 1, 0));
        for (int i = 0; i < (int)v.size(); i++) {
            for (int j = 0; j < (int)v[0].size(); j++) {
                data[i + 1][j + 1] =
                    data[i + 1][j] + data[i][j + 1] - data[i][j] + v[i][j];
            }
        }
    }
    //[a,b)×[c,d)の和を計算
    long long int sum(int a, int b, int c, int d) {
        return data[b][d] - data[b][c] - data[a][d] + data[a][c];
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> train(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        train[l - 1][r - 1]++;
    }
    cumulative_sum_2d cum(train);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << cum.sum(x - 1, y, x - 1, y) << endl;
    }
}
