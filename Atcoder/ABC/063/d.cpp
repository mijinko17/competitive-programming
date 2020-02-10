#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<lint> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    lint ok = INT_MAX, no = 0;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        lint require = 0;
        for (int i = 0; i < n; i++) {
            lint rem = max(0LL, h[i] - mid * b);
            require += (rem + a - b - 1) / (a - b);
        }
        if (require <= mid) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << ok << endl;
}
