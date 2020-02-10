#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    int n, m;
    cin >> n >> m;
    // dp[i][j]:長さiで最大値jなる数列の個数
    vector<vector<lint>> dp(m + 1, vector<lint>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
            }
        }
    }
    lint ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            lint temp = (dp[m][i] * dp[m][n - j + 1]) % mod;
            ans = (ans + temp) % mod;
        }
    }
    cout << ans << endl;
}
