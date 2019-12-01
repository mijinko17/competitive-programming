#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    // dp1[i][j]:[0,i)まで使用、時間j以内での最大値
    vector<vector<int>> dp1(n + 1, vector<int>(t, 0));
    // dp2[i][j]:[i,n)まで使用、時間j以内での最大値
    vector<vector<int>> dp2(n + 1, vector<int>(t, 0));
    // dp1
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < t; j++) {
            dp1[i + 1][j] = max(dp1[i][j], dp1[i + 1][j - 1]);
            if (j - a[i] >= 0) {
                dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j - a[i]] + b[i]);
            }
        }
    }
    // dp2
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < t; j++) {
            dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]);
            if (j - a[i] >= 0) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i]] + b[i]);
            }
        }
    }
    int ans = 0;
    // iを最後に食べる
    for (int i = 0; i < n; i++) {
        //前半にj掛ける
        for (int j = 0; j < t; j++) {
            ans = max(ans, dp1[i][j] + dp2[i + 1][t - 1 - j] + b[i]);
        }
    }
    cout << ans << endl;
}
