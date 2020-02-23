#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * m * n - 2 * m - 2 * n) {
        cout << "NO" << endl;
        return 0;
    }
    string ans;
    ans += string(m, 'R');
    ans += string(m, 'L');
    for (int i = 0; i < n - 1; i++) {
        ans += 'D';
        for (int j = 0; j < m - 1; j++) {
            ans += "RUD";
        }
        ans += string(m, 'L');
    }
    ans += string(n - 1, 'U');
    cout << "YES" << endl;
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << 1 << " " << ans[i] << endl;
    }
}
