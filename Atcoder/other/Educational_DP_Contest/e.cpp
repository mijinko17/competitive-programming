#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<lint> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    // dp[i][j]:品物を[0,i)まで使って価値jを作るときの最小の重さ
    vector<vector<lint>> dp(n + 1, vector<lint>(1e+5 + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1e+5; j++) {
            if (j - v[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else if (dp[i - 1][j - v[i - 1]] == LLONG_MAX) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] =
                    min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
            }
        }
    }
    for (int i = 1e+5; i >= 0; i--) {
        if (dp[n][i] <= limit) {
            cout << i << endl;
            return 0;
        }
    }
}
