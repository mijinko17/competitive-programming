#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, m, d;
    cin >> n >> m >> d;
    double ans = (n - 2 * d >= 0 && d != 0) ? 2.0 * (n - d) * (m - 1) / (n * n)
                                            : 1.0 * (m - 1) / n;
    cout << setprecision(10) << ans << endl;
    cout << setprecision(10) << endl;
}
