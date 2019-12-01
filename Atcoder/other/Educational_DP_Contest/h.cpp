#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    // dp[i][j]:(i-1,j-1)への行き方
    vector<vector<lint>> dp(h + 1, vector<lint>(w + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i - 1][j - 1] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[h][w] << endl;
}
