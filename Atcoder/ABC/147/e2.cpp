#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> d(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int temp;
            cin >> temp;
            d[i][j] = abs(a[i][j] - temp);
        }
    }
    int m = (h + w) * 80 + 2;
    vector<vector<vector<bool>>> dp(
        h, vector<vector<bool>>(w, vector<bool>(m, false)));
    dp[0][0][d[0][0]] = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < m; k++) {
                if (!dp[i][j][k]) continue;
                if (i + 1 < h) {
                    int diff_down = d[i + 1][j];
                    dp[i + 1][j][abs(k + diff_down)] =
                        dp[i + 1][j][abs(k + diff_down)] || dp[i][j][k];
                    dp[i + 1][j][abs(k - diff_down)] =
                        dp[i + 1][j][abs(k - diff_down)] || dp[i][j][k];
                }
                if (j + 1 < w) {
                    int diff_right = d[i][j + 1];
                    dp[i][j + 1][abs(k + diff_right)] =
                        dp[i][j + 1][abs(k + diff_right)] || dp[i][j][k];
                    dp[i][j + 1][abs(k - diff_right)] =
                        dp[i][j + 1][abs(k - diff_right)] || dp[i][j][k];
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (dp[h - 1][w - 1][i]) {
            cout << i << endl;
            return 0;
        }
    }
}
