#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, q;
vector<int> x, r, h;

double subvolume(int k, int a, int b) {
    if (x[k] > b || x[k] + h[k] < a) return 0.0;
    int p = max(x[k] + h[k] - b, 0);
    int q = min(x[k] + h[k] - a, h[k]);
    return 1.0 * r[k] * r[k] * M_PI * h[k] / 3 * (q * q * q - p * p * p) / (h[k] * h[k] * h[k]);
}

int main() {
    cin >> n >> q;
    x.resize(n);
    r.resize(n);
    h.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> r[i] >> h[i];
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += subvolume(i, a, b);
        }
        cout << setprecision(12) << ans << endl;
    }
}
