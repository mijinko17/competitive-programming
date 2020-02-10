#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> d(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int temp;
            cin >> temp;
            d[i][j] = abs(temp - a[i][j]);
        }
    }
    const int offset = 12800;
    vector<vector<bitset<offset * 2>>> dp(h, vector<bitset<offset * 2>>(w, 0));
    dp[0][0][offset + d[0][0]] = dp[0][0][offset - d[0][0]] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i + 1 < h) {
                int diff = d[i + 1][j];
                dp[i + 1][j] |= dp[i][j] << diff;
                dp[i + 1][j] |= dp[i][j] >> diff;
            }
            if (j + 1 < w) {
                int diff = d[i][j + 1];
                dp[i][j + 1] |= dp[i][j] << diff;
                dp[i][j + 1] |= dp[i][j] >> diff;
            }
        }
    }
    for (int i = 0; i < 12800; i++) {
        if (dp[h - 1][w - 1][offset + i] || dp[h - 1][w - 1][offset + i]) {
            cout << i << endl;
            return 0;
        }
    }
}
