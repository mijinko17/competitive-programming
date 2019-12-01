#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    double ans;
    if (2 * x <= a * a * b) {
        ans = atan(b * b * a / (2 * x)) * 180.0 / M_PI;
    } else {
        ans = atan((2 * (a * a * b - x)) / (a * a * a)) * 180.0 / M_PI;
    }
    cout << setprecision(10) << ans << endl;
}
