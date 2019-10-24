#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    // dp[i]:i番目の足場に着くまでの最小のコスト
    vector<lint> dp(n, 0);
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 2] + abs(h[i - 2] - h[i]),
                    dp[i - 1] + abs(h[i - 1] - h[i]));
    }
    cout << dp[n - 1] << endl;
}
