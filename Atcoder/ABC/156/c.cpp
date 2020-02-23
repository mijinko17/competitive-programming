#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    lint n;
    cin >> n;
    vector<lint> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    lint ans = LLONG_MAX;
    for (int p = 1; p <= 100; p++) {
        lint cand = 0;
        for (int i = 0; i < n; i++) {
            cand += (x[i] - p) * (x[i] - p);
        }
        chmin(ans, cand);
    }
    cout << ans << endl;
}
