#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k, s;

int main() {
    cin >> n >> k >> s;
    // if (k == n) {
    //     for (int i = 0; i < n; i++) {
    //         cout << s << " ";
    //     }
    //     cout << endl;
    //     return 0;
    // } else {
    //     if (s < 3) {
    //         for (int i = 0; i < k; i++) {
    //             cout << s << " ";
    //         }
    //         for (int i = k; i < n; i++) {
    //             cout << s + 1 << " ";
    //         }
    //     }
    // }
    for (int i = 0; i < k; i++) {
        cout << s << " " << endl;
    }
    if (s == 1e+9) {
        for (int i = k; i < n; i++) {
            cout << s - 1 << endl;
        }
    } else {
        for (int i = k; i < n; i++) {
            cout << s + 1 << endl;
        }
    }
}
