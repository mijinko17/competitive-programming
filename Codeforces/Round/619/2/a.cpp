#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.length();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != c[i] && b[i] != c[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
