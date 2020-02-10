#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint h, n;
vector<lint> a, b;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> h >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<lint>> dp(n + 1, vector<lint>(h + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            chmin(dp[i + 1][j], dp[i][j]);
            // cout << dp[i + 1][min(j + a[i], h)] << " " << dp[i][j] + b[i]
            //      << endl;
            if (dp[i][j] == LLONG_MAX) {
                continue;
            }
            if (j + a[i] <= h) {
                chmin(dp[i + 1][j + a[i]], dp[i][j] + b[i]);
            } else {
                chmin(dp[i + 1][h], dp[i][j] + b[i]);
            }
        }
        for (int k = 0; k <= h; k++) {
            //       cout << dp[i + 1][k] << endl;
        }
    }
    cout << dp[n][h] << endl;
}
