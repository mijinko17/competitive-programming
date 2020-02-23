#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string s;

int main() {
    cin >> s;
    lint n = s.length();
    // dp[i]:上[0,i)桁決めた時の最小
    vector<lint> dp_just(n);
    vector<lint> dp_ex(n);
    for (int i = 0; i < n; i++) {
        dp_just[i + 1] = dp_just[i] + (s[i] - '0');
    }
}
