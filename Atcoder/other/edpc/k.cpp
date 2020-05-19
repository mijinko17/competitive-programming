#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, k;
vector<int> a;

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // dp[i]:残りi個で手番が回ってきたら勝てるか?
    vector<bool> dp(k + 1);
    for (int i = 0; i <= k; i++) {
        bool res = false;
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && !dp[i - a[j]]) {
                res = true;
                break;
            }
        }
        dp[i] = res;
    }
    if (dp[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
