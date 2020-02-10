#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        bool flag = false;
        for (int i = 0; i * i <= 2 * d; i++) {
            if (n >= i + (d + i) / (i + 1)) {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        }
    }
}
