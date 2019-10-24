#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    // dp[i][j]:右端がs[i-1],t[j-1]なる等しい部分列の数
    vector<vector<lint>> dp(n + 1, vector<lint>(m + 1, 0));
    // sum[i][j]:dp[0][0]~dp[i-1][j-1]の和
    vector<vector<lint>> sum(n + 1, vector<lint>(m + 1, 0));
    dp[0][0] = 1;
    lint ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                        dp[i - 1][j - 1];
            sum[i][j] %= mod;
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = sum[i][j];
            } else {
                dp[i][j] = 0;
            }
            ans += dp[i][j];
            ans %= mod;
        }
    }
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
}
