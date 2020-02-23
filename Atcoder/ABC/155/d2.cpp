#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;
vector<double> a;

bool check(double m) {
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans += n - 1;
        } else if (a[i] > 0) {
            double pair = m / a[i];
        }
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
}
