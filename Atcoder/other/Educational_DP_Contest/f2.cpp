#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    // dp[i][j]:s[0,i),t[0,j)での最長共通部分列の長さ
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1];
            if (s[i - 1] == t[j - 1]) dp[i][j]++;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    int x = m, y = n;
    string ans = "";
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x - 1][y])
            x--;
        else if (dp[x][y] == dp[x][y - 1])
            y--;
        else {
            ans = s[x - 1] + ans;
            x--, y--;
        }
    }
    cout << ans << endl;
}
