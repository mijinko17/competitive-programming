#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);
    lint sum = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        sum += a[i];
    }
    lint ans = 0;
    if (m * n - sum > k) {
        ans = -1;
    } else {
        ans = max(0LL, m * n - sum);
    }
    cout << ans << endl;
}
