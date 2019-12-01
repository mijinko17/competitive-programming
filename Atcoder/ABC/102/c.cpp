#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

long double sadness(vector<int>& a, long double b) {
    long double res = 0;
    for (int i = 0; i < a.size(); i++) {
        res += abs((long double)a[i] - b);
    }
    return res;
}

// upper<=x<lowerとしたい
int upper(double x) {
    return x >= 0 ? (int)x + 1 : (int)x;
}
int lower(double x) {
    return upper(x) - 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long double M = INT_MIN, m = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i + 1;
        M = max(M, (long double)a[i]);
        m = min(m, (long double)a[i]);
    }
    while (M - m >= 0.5) {
        long double l = (m * 2 + M) / 3;
        long double r = (M * 2 + m) / 3;
        if (sadness(a, l) < sadness(a, r)) {
            M = r;
        } else {
            m = l;
        }
    }
    lint ans = LLONG_MAX;
    ans = min(ans, (lint)sadness(a, upper(m)));
    ans = min(ans, (lint)sadness(a, upper(M)));
    ans = min(ans, (lint)sadness(a, lower(m)));
    ans = min(ans, (lint)sadness(a, lower(M)));
    cout << ans << endl;
}
