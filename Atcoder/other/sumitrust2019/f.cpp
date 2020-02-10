#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    vector<lint> t(2), a(2), b(2);
    cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];
    vector<lint> c = {a[0] * t[0] + a[1] * t[1], b[0] * t[0] + b[1] * t[1]};
    if (c[0] == c[1]) {
        cout << "infinity" << endl;
        return 0;
    }
    if (c[0] < c[1]) {
        swap(a[0], b[0]);
        swap(a[1], b[1]);
    }
    lint ans = 0;
    if (b[0] > a[0]) {
        ans += t[0] * (b[0] - a[0]) / (c[0] - c[1]);
    }
    if (a[1] > b[1]) {
        ans += t[1] * (a[1] - b[1]) / (c[0] - c[1]);
    }
    if (t[0] * (b[0] - a[0]) % (c[0] - c[1]) == 0) {
        ans--;
    }
    cout << ans << endl;
}
