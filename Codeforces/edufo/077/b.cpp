#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        lint a, b;
        cin >> a >> b;
        lint ok = 0, no = min(a, b / 2) + 1;
        while (abs(ok - no) > 1) {
            lint mid = (ok + no) / 2;
            if (a - mid <= 2 * (b - 2 * mid)) {
                ok = mid;
            } else {
                no = mid;
            }
        }
        if (a - ok == 2 * (b - 2 * ok)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
