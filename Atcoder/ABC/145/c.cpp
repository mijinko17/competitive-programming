#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

long double dfs(int n, int now, int arrived, vector<lint>& x, vector<lint>& y) {
    if (arrived == (1 << n) - 1) {
        return 0;
    } else {
        long double res = 0;
        for (int i = 0; i < n; i++) {
            if (arrived & (1 << i)) {
                continue;
            } else {
                lint x_dist = x[now] - x[i];
                lint y_dist = y[now] - y[i];
                res += sqrt(x_dist * x_dist + y_dist * y_dist) +
                       dfs(n, i, arrived | (1 << i), x, y);
            }
        }
        return res;
    }
}

int main() {
    int n;
    cin >> n;
    vector<lint> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dfs(n, i, (1 << i), x, y) / fac;
    }
    cout << setprecision(10) << ans << endl;
}
