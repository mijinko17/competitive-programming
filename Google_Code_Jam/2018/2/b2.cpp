#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // dp[i][j]:赤i,青j
    vector<vector<lint>> dp(501, vector<lint>(501, 0));
    for (int i = 0; i <= 40; i++) {
        for (int j = 0; j <= 40; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            for (int k = 500; k >= i; k--) {
                for (int l = 500; l >= j; l--) {
                    chmax(dp[k][l], dp[k - i][l - j] + 1);
                }
            }
        }
    }
    cout << '{';
    for (int i = 0; i <= 500; i++) {
        cout << '{';
        for (int j = 0; j <= 500; j++) {
            cout << dp[i][j] << (j != 500 ? "," : "");
        }
        cout << '}' << (i != 500 ? "," : "\n");
    }
    cout << '}' << endl;
    ;
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        lint r, b;
        cin >> r >> b;
        lint ans = 0;
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= b; j++) {
                chmax(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
