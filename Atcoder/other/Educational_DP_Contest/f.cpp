#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

struct info {
    // s_from,t_from:s,tの末端
    int s_from;
    int t_from;
    int length;
    // isChoiced:i-1,j-1が部分列として使われてるか
    bool used;
    info(int s, int t, int l, bool c)
        : s_from(s), t_from(t), length(l), used(c) {
    }
    info() {
    }
};

int main() {
    string s, t;
    cin >> s >> t;
    int m = s.length(), n = t.length();
    pair<int, int> ed = {0, 0};
    int M = 0;
    // dp[i][j]:s[0,i),t[0,j)での共通部分列で最長のやつの長さと一個前を保存
    vector<vector<info>> dp(m + 1, vector<info>(n + 1, info(-1, -1, 0, false)));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            info c1, c2, c3;
            // c1
            c1 = dp[i - 1][j];
            if (dp[i - 1][j].used) {
                c1.s_from = i - 2;
                c1.t_from = j - 1;
            }
            // c2
            c2 = dp[i][j - 1];
            if (dp[i][j - 1].used) {
                c2.s_from = i - 1;
                c2.t_from = j - 2;
            }
            // c3
            c3 = dp[i - 1][j - 1];
            if (dp[i - 1][j - 1].used) {
                c2.s_from = i - 2;
                c2.t_from = j - 2;
            }
            if (s[i - 1] == t[j - 1]) {
                c3.length++;
                c3.used = true;
            }
            // dp遷移
            dp[i][j] = c1;
            if (dp[i][j].length < c2.length) {
                dp[i][j] = c2;
            }
            if (dp[i][j].length < c3.length) {
                dp[i][j] = c3;
            }
            if (dp[i][j].length > M) {
                ed = {i, j};
            }
        }
    }
    string ans(M, '#');
    ans[M - 1] = s[dp[ed.first][ed.second].s_from];
    for (int i = 0; i < M; i++) {
    }
}
