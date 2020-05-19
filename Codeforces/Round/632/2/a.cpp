#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> ans(n, string(m, 'B'));
        for (int i = 0; i < n; i++) {
            int offset = i % 2 == 0 ? 1 : 0;
            for (int j = 0; 2 * j + offset < m; j++) {
                ans[i][2 * j + offset] = 'W';
            }
        }
        if (n * m % 2 == 0) {
            if (n % 2 == 0) {
                ans[n - 1][0] = 'B';
            } else {
                ans[0][m - 1] = 'B';
            }
        }
        for (auto e : ans) {
            cout << e << endl;
        }
    }
}
