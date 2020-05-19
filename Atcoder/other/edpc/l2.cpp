#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i][j]:[0,i),[j,n)を掘った段階からの"X-Y"
    vector<vector<lint>> dp(n + 1, vector<lint>(n + 1, 0));
    // i:掘る合計
    for (int i = n - 1; i >= 0; i--) {
        // j:左から掘る個数
        for (int j = 0; j <= i; j++) {
            dp[j][n - i + j] =
                max(a[j] - dp[j + 1][n - i + j], a[n - i + j - 1] - dp[j][n - i + j - 1]);
        }
    }
    cout << dp[0][n] << endl;
}
