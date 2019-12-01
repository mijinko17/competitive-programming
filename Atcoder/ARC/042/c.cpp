#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    sort(all(ab), greater<pair<int, int>>());
    // dp[i][j]:[0,i)だけつかう、j円以内での最大値
    vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= p; j++) {
            auto now = ab[i];
            dp[i + 1][j] = dp[i][j];
            if (j - now.first >= 0)
                dp[i + 1][j] =
                    max(dp[i + 1][j], dp[i][j - now.first] + now.second);
        }
    }
    int ans = 0;
    //最小をiとする
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i][p] + ab[i].second);
    }
    cout << ans << endl;
}
