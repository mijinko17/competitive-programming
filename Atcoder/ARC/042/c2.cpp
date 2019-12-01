#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(x) (x).begin(), (x).end()
int main() {
    int n, p;
    cin >> n >> p;
    vector<int> v(n), w(n);
    vector<pair<int, int>> wv(n);
    for (int i = 0; i < n; i++) {
        cin >> wv[i].first >> wv[i].second;
    }
    sort(all(wv), greater<pair<int, int>>());
    vector<vector<int>> dp(n, vector<int>(p + 5010, -1));
    for (int i = 0; i < n; i++) {
        w[i] = wv[i].first;
        v[i] = wv[i].second;
    }

    // dp[i][j]:i番目までの荷物を重さがj以下で入れられる最大値
    for (int j = 0; j < p + 5010; j++) {
        if (w[0] > j) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = v[0];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < p + 5010; j++) {
            if (j - w[i + 1] < 0)
                dp[i + 1][j] = dp[i][j];
            else
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i + 1]] + v[i + 1]);
        }
    }
    int ans = dp[n - 1][p];
    for (int t = p + 1; t < p + 5010; t++) {
        for (int i = 0; i < n; i++) {
            if (t - w[i] <= p) {
                ans = max(ans, dp[i][t]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            if (dp[i][j] > dp[i][j + 1]) {
                cout << i << " " << j << endl;
            }
        }
        cout << endl;
    }
    cout << ans << endl;
}
