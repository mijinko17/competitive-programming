#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        lint r, b;
        cin >> r >> b;
        vector<pair<int, int>> item;
        int max_r = (int)sqrt(2 * r) + 1;
        int max_b = (int)sqrt(2 * b) + 1;
        int num = (max_r + 1) * (max_b + 1);
        item.reserve(num);
        for (int i = 0; i <= max_r; i++) {
            for (int j = 0; j <= max_b; j++) {
                if (i + j == 0) {
                    continue;
                }
                item.push_back({i, j});
            }
        }
        // dp[i][j][k]:i番目まで見て赤j,青kでの最大
        vector<vector<vector<lint>>> dp(2, vector<vector<lint>>(r + 1, vector<lint>(b + 1, 0)));
        for (int i = 0; i < item.size(); i++) {
            for (int j = 0; j <= r; j++) {
                for (int k = 0; k <= b; k++) {
                    chmax(dp[(i + 1) % 2][j][k], dp[i % 2][j][k]);
                    if (j + item[i].first <= r && k + item[i].second <= b) {
                        chmax(dp[(i + 1) % 2][j + item[i].first][k + item[i].second],
                              dp[i % 2][j][k] + 1);
                    }
                }
            }
        }
        // for (int i = 0; i <= item.size(); i++) {
        //    for (int j = 0; j <= r; j++) {
        //        for (int k = 0; k <= b; k++) {
        //            cout << dp[i][j][k] << ' ';
        //        }
        //        cout << endl;
        //    }
        //    cout << endl;
        //}
        lint ans = 0;
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= b; j++) {
                chmax(ans, dp[item.size() % 2][i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
