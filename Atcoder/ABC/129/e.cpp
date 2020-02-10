#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e9 + 7;
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<lint>> dp(2, vector<lint>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        // 0->0
        if (s[i] == '1') {
            dp[0][i + 1] += (dp[0][i] * 2) % mod;
            dp[0][i + 1] %= mod;
        } else {
            dp[0][i + 1] += dp[0][i];
            dp[0][i + 1] %= mod;
        }
        // 0->1
        if (s[i] == '1') {
            dp[1][i + 1] += dp[0][i];
            dp[1][i + 1] %= mod;
        }
        // 1->1
        dp[1][i + 1] += dp[1][i] * 3;
        dp[1][i + 1] %= mod;
    }
    cout << (dp[0][n] + dp[1][n]) % mod << endl;
}
