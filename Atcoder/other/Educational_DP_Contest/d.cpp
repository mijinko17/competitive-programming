#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, limit;
    cin >> n >> limit;
    vector<lint> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    // dp[i]][j]:品物を[0,i)まで使うときの重さjでの価値最大
    vector<vector<lint>> dp(n + 1, vector<lint>(limit + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= limit; j++) {
            if (j - w[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    cout << *(max_element(all(dp[n]))) << endl;
}
