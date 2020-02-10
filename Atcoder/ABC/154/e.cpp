#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string n;
int k;

int main() {
    cin >> n >> k;
    int sz = n.length();
    // dp0:ジャスト, dp1:未満
    vector<vector<lint>> dp0(sz + 2, vector<lint>(sz + 2, 0));
    vector<vector<lint>> dp1(sz + 2, vector<lint>(sz + 2, 0));
    dp0[0][1] = 1;
    dp1[0][1] = n[0] - '0' - 1;
    // i:n[i]
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j <= sz + 1; j++) {
            if (n[i] == '0') {
                dp0[i][j] = dp0[i - 1][j];
            } else {
                dp0[i][j + 1] += dp0[i - 1][j];
                dp1[i][j + 1] += dp0[i - 1][j] * (n[i] - '0' - 1);
                dp1[i][j] += dp0[i - 1][j];
            }
            dp1[i][j + 1] += dp1[i - 1][j] * 9;
            dp1[i][j] += dp1[i - 1][j];
        }
        dp1[i][1] += 9;
    }
    cout << dp0[sz - 1][k] + dp1[sz - 1][k] << endl;
}
