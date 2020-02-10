#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

double met(double x, double y, double z, double w) {
    double d = x - z, e = y - w;
    return sqrt(d * d + e * e);
}

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = DBL_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double a = x[i], b = y[i], c = x[j], d = y[j], e = x[k],
                       f = y[k];
                double aa = a * a, bb = b * b, cc = c * c, dd = d * d,
                       ee = e * e, ff = f * f;
                double px, py;
                py = ((e - a) * (aa + bb - cc - dd) -
                      (c - a) * (aa + bb - ee - ff)) /
                     (2 * (e - a) * (b - d) - 2 * (c - a) * (b - f));
                if (c - a == 0) {
                    px = (2 * (b - f) * py - aa - bb + ee + ff) / (2 * (e - a));
                } else {
                    px = (2 * (b - d) * py - aa - bb + cc + dd) / (2 * (c - a));
                }
                double r = met(px, a, py, b);
                bool flag = true;
                for (int l = 0; l < n; l++) {
                    if (met(px, x[l], py, y[l]) <= r) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                }
            }
        }
    }
}
