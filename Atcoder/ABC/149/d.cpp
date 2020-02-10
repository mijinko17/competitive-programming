#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, k, r, s, p;
string t;

int main() {
    cin >> n >> k >> r >> s >> p >> t;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int max_k = (n - i + k - 1) / k;
        // dp[i][j]:j-1番目にiをだす
        vector<vector<int>> dp(3, vector<int>(max_k + 1, 0));
        for (int j = 0; j < max_k; j++) {
            dp[0][j + 1] =
                max(dp[1][j], dp[2][j]) + (t[i + j * k] == 's' ? r : 0);
            dp[1][j + 1] =
                max(dp[2][j], dp[0][j]) + (t[i + j * k] == 'p' ? s : 0);
            dp[2][j + 1] =
                max(dp[0][j], dp[1][j]) + (t[i + j * k] == 'r' ? p : 0);
        }
        ans += max({dp[0][max_k], dp[1][max_k], dp[2][max_k]});
    }
    cout << ans << endl;
}
