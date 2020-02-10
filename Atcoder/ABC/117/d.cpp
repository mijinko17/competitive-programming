#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i][j]:(i:未満フラグ),(j:決めた桁数)
    vector<vector<lint>> dp(2, vector<lint>(51, -1));
    dp[0][0] = 0;
    for (int i = 0; i < 50; i++) {
        lint mask = 1LL << (50 - 1 - i);
        // 50-1-iビット目が何本立ってるか調べる
        lint num_bit = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] & mask) num_bit++;
        }
        // 0->0
        if (k & mask) {
            dp[0][i + 1] = dp[0][i] + (n - num_bit) * mask;
        } else {
            dp[0][i + 1] = dp[0][i] + num_bit * mask;
        }
        // 0->1
        if (k & mask) {
            dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + num_bit * mask);
        }
        // 1->1
        if (dp[1][i] != -1) {
            dp[1][i + 1] =
                max(dp[1][i + 1], dp[1][i] + max(num_bit, n - num_bit) * mask);
        }
    }
    cout << max(dp[0][50], dp[1][50]) << endl;
}
