#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 3 == 0) {
        string s = "aa.", t = "..a";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 3; j++) {
                if (i % 3 == 0) {
                    cout << s;
                } else {
                    cout << t;
                }
            }
            cout << endl;
        }
    } else if (n % 4 == 0) {
        vector<string> b = {"abee", "abff", "ccgh", "ddgh"};
        vector<string> ans(n, string(n, 'x'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = b[i % 4][j % 4];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << endl;
        }
    } else {
        cout << -1 << endl;
    }
}
