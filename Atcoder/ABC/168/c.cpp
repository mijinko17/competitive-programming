#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    pair<double, double> p = {cos(M_PI * (h + m / 60) / 6) * a, sin(M_PI * (h + m / 60) / 6) * a};
    pair<double, double> q = {cos(M_PI * m / 30) * b, sin(M_PI * m / 30) * b};
    pair<double, double> diff = {p.first - q.first, p.second - q.second};
    double ans = sqrt(diff.first * diff.first + diff.second * diff.second);
    cout << setprecision(12) << ans << endl;
}
