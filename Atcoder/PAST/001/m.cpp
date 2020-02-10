#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
vector<double> a, b, c, d;

double solve() {
    double ok = 0, no = 1000000000;
    while (abs(ok - no) > 0.0000001) {
        double mid = ok / 2 + no / 2;
        vector<double> cand(5, -DBL_MAX);
        for (int i = 0; i < n + 1; i++) {
            cand.push_back(b[i] - a[i] * mid);
            cand.erase(min_element(cand.begin(), cand.end()));
        }
        double judge = accumulate(cand.begin(), cand.end(), 0.0);
        if (judge >= 0) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    return ok;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m;
    a.resize(n), b.resize(n);
    c.resize(m), d.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    double ans = 0;
    for (int i = 0; i < m; i++) {
        a.push_back(c[i]);
        b.push_back(d[i]);
        chmax(ans, solve());
        a.pop_back();
        b.pop_back();
    }
    cout << setprecision(12) << ans << endl;
}
