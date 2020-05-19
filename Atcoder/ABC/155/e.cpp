#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

string s;

int main() {
    cin >> s;
    s = '0' + s;
    lint n = s.length();
    // dp[0][i]:[0,i)までの会計の仕方で、次に繰り下がれないような方法での最小
    // dp[1][i]:[0,i)までの会計の仕方で、次に繰り下がれるような方法での最小
    vector<vector<int>> dp(2, vector<int>(n + 1, INT_MAX / 2));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int k = s[i] - '0';
        chmin(dp[0][i + 1], dp[0][i] + k);
        if (k != 9) chmin(dp[1][i + 1], dp[0][i] + k + 1);
        chmin(dp[0][i + 1], dp[1][i] + 10 - k);
        chmin(dp[1][i + 1], dp[1][i] + 9 - k);
    }
    cout << dp[0][n] << endl;
}
