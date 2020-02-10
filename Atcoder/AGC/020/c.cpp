#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    const int m = 4000001;
    bitset<m> dp(1);
    for (int i = 0; i < n; i++) {
        dp = dp | (dp << a[i]);
    }
    int ans = (sum + 1) / 2;
    while (1) {
        if (dp[ans]) {
            cout << ans << endl;
            return 0;
        } else {
            ans++;
        }
    }
}
