#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    // dp[i][j]:末端がi-1,j-1なる連続部分文字列で最長のやつの長さ
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = min(dp[i - 1][j - 1] + 1, abs(i - j));
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    cout << ans << endl;
}
