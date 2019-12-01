#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> q[i];
    }
    p[n] = p[0], q[n] = q[0];
    double ans = DBL_MAX;
    //頂点への距離
    for (int i = 0; i < n; i++) {
        int x_dist = x - p[i], y_dist = y - q[i];
        ans = min(ans, sqrt(x_dist * x_dist + y_dist * y_dist));
    }
    //辺(i,i+1)への距離
    for (int i = 0; i < n; i++) {
        int a = p[i] - p[i + 1];
        int b = q[i] - q[i + 1];
        double t = 1.0 * ((p[i] - x) * a + (q[i] - y) * b) / (a * a + b * b);
        if (t <= 0 || t >= 1) continue;
        double s = 1 - t;
        double x_dist = s * p[i] + t * p[i + 1] - x;
        double y_dist = s * q[i] + t * q[i + 1] - y;
        ans = min(ans, sqrt(x_dist * x_dist + y_dist * y_dist));
    }
    cout << setprecision(10) << ans << endl;
}
