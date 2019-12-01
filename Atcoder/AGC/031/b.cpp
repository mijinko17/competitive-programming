#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    int n;
    cin >> n;
    int temp;
    vector<int> c(1);
    cin >> c[0];
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (c.back() != temp) {
            c.push_back(temp);
        }
    }
    int m = c.size();
    // last[i]:今まで見た中で、右端の色がiなる最後のdp
    unordered_map<int, lint> last;
    // dp[i]:[0,i)までの答え
    vector<lint> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        dp[i + 1] = (dp[i] + last[c[i]]) % mod;
        last[c[i]] = dp[i + 1];
    }
    cout << dp[m] << endl;
}
