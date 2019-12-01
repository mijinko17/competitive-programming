#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    a[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + a[i + 1] > x) {
            ans += a[i] + a[i + 1] - x;
            a[i + 1] = x - a[i];
        }
    }
    cout << ans << endl;
}
