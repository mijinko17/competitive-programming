#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 1e+9 + 7;
lint h, w, k;

bool isvalid(bitset<8> b) {
    for (int i = 0; i < w - 2; i++) {
        if (b[i] == 1 && b[i + 1] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> h >> w >> k;
    vector<vector<lint>> dp(h + 1, vector<lint>(w, 0));
    dp[0][0] = 1;
    //高さiのところを見る
    for (int i = 0; i < h; i++) {
        //貼り方全部見る
        for (int j = 0; j < (1 << (w - 1)); j++) {
            bitset<8> b(j);
            if (!isvalid(b)) continue;
            for (int k = 0; k < w; k++) {
                if (k - 1 >= 0 && b[k - 1]) {
                    dp[i + 1][k - 1] += dp[i][k];
                    dp[i + 1][k - 1] %= mod;
                } else if (k + 1 < w && b[k]) {
                    dp[i + 1][k + 1] += dp[i][k];
                    dp[i + 1][k + 1] %= mod;
                } else {
                    dp[i + 1][k] += dp[i][k];
                    dp[i + 1][k] %= mod;
                }
            }
        }
    }
    cout << dp[h][k - 1] << endl;
}
