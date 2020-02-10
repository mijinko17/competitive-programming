#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
vector<double> a, b, c, d;

// めぐる式二分探索
template <typename T>
T meguru_BinarySearch(T ok, T no, function<bool(T)> isValid, T diff = 1) {
    while (abs(ok - no) > diff) {
        T mid = (ok + no) / 2;
        if (isValid(mid))
            ok = mid;
        else
            no = mid;
    }
    return ok;
}

bool check(double x) {
    double help = -DBL_MAX;
    for (int i = 0; i < m; i++) {
        help = max(help, d[i] - c[i] * x);
    }
    vector<double> cand(5, -DBL_MAX);
    cand[0] = help;
    for (int i = 0; i < n; i++) {
        cand.push_back(b[i] - a[i] * x);
        cand.erase(min_element(cand.begin(), cand.end()));
    }
    double sum = accumulate(cand.begin(), cand.end(), 0.0);
    return sum >= 0;
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
    cout << setprecision(12)
         << meguru_BinarySearch<double>(0.0, 1000000.0, check, 0.000000001)
         << endl;
}
