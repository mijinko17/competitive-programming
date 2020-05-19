#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b, h, m;
    cin >> a >> b >> h >> m;
    double pi = M_PI;
    double diff = pi * h / 6.0 - pi * m / 30.0;
    double temp = 1.0 + a * a + b * b - 2.0 * a * b * cos(diff);
    double ans = sqrt(temp);
    cout << setprecision(12) << ans << endl;
}
