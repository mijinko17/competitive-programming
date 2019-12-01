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
    vector<vector<lint>> dp1(n + 1, vector<lint>(t, 0));
    vector<vector<lint>> dp2(n + 1, vector<lint>(t, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < t; j++) {
            dp1[i + 1][j] = max(dp1[i + 1][j], dp1[i][j]);
            dp2[i + 1][j] = max(dp2[i + 1][j], dp2[i][j]);
            if (j + a[i] < t) {
                dp1[i + 1][j + a[i]] =
                    max(dp1[i + 1][j + a[i]], dp1[i][j] + b[i]);
                dp2[i + 1][j + a[i]] =
                    max(dp2[i + 1][j + a[i]], dp2[i][j] + b[i]);
            }
            dp2[i + 1][j] = max(dp2[i + 1][j], dp1[i][j] + b[i]);
        }
    }
    lint ans = 0;
    for (int i = 0; i < t; i++) {
        ans = max(dp1[n][i], ans);
        ans = max(dp2[n][i], ans);
    }
    cout << ans << endl;
}
