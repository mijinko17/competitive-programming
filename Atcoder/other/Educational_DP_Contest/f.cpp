#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    // dp[i][j]:s[0,i-1),t[0,j-1)での最長共通部分列
    vector<vector<string>> dp(m + 1, vector<string>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j - 1].length() > dp[i - 1][j].length()) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
            if (s[i - 1] == t[j - 1]) {
                if (dp[i - 1][j - 1].length() + 1 > dp[i][j].length()) {
                    dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
                }
            }
        }
    }
    cout << dp[m][n] << endl;
}
