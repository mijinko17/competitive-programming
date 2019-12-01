#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        int left = x[i], right = x[i + k - 1];
        ans = min(ans, abs(left) + abs(left - right));
        ans = min(ans, abs(right) + abs(left - right));
    }
    cout << ans << endl;
}
