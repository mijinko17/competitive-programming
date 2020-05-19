#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<double> p;

int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    // dp[i][j]:[0,i)まで投げて表がj枚出る確率
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + 1][j + 1] += dp[i][j] * p[i];
            dp[i + 1][j] += dp[i][j] * (1 - p[i]);
        }
    }
    double ans = 0.0;
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans += dp[n][i];
    }
    cout << setprecision(12) << ans << endl;
}
