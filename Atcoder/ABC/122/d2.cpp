#include <bits/stdc++.h>
using namespace std;

// s[i]とs[i+1]を入れ替えた文字列を出力
string trans(string s, int i) {
    swap(s[i], s[i + 1]);
    return s;
}

//長さ3の文字列が"AGC"か判定
bool notAGC(string s) {
    string a = "agc";
    if (s == a || trans(s, 0) == a || trans(s, 1) == a) return false;
    return true;
}

int main() {
    for (int n = 3; n <= 100; n++) {
        long long int p = 1e+9 + 7;
        // dp[i][s]:長さiのnotAGCで右3つがsなるものの数
        vector<unordered_map<string, long long int>> dp(n + 1);
        vector<string> c = {"a", "c", "g", "t"};
        // dp[3]を完成させる
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    string temp = c[i] + c[j] + c[k];
                    if (notAGC(temp)) {
                        dp[3][temp]++;
                    }
                }
            }
        }
        // dp[i(>3)]を完成させる
        for (int i = 3; i < n; i++) {
            for (auto itr = dp[i].begin(); itr != dp[i].end(); itr++) {
                for (int j = 0; j < 4; j++) {
                    string temp1 = (*itr).first.substr(1) + c[j];
                    string temp2 = (*itr).first.substr(0, 2) + c[j];
                    string temp3 = trans((*itr).first, 0).substr(1) + c[j];
                    if (notAGC(temp1) && temp2 != "agc" && temp3 != "agc") {
                        dp[i + 1][temp1] += (*itr).second;
                        dp[i + 1][temp1] %= p;
                    }
                }
            }
        }
        long long int ans = 0;
        for (auto itr = dp[n].begin(); itr != dp[n].end(); itr++) {
            ans += (*itr).second;
            ans %= p;
        }
        cout << ans << endl;
    }
    return 0;
}
