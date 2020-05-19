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
    // dp[i][j]:左からi,右からj個掘った段階から最適に行動したときの"X-Y"
    vector<vector<lint>> dp(n + 1, vector<lint>(n + 1, 0));
    // i:掘る数の合計
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j][i - j] = max(a[j] - dp[j + 1][i - j], a[n - i + j - 1] - dp[j][i - j + 1]);
        }
    }
    cout << dp[0][0] << endl;
}
