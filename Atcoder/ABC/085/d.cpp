#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, h;
vector<lint> a, b;

int main() {
    cin >> n >> h;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    lint repeater = *max_element(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<lint>());
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] <= repeater) {
            break;
        }
        h -= b[i];
        ans++;
        if (h <= 0) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans + (h + repeater - 1) / repeater << endl;
}
