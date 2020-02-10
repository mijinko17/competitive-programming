#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    if (c == 1 && r == 1) {
        cout << 0 << endl;
    } else {
        if (r == 1) {
            for (int i = 0; i < c; i++) {
                cout << i + 2 << " ";
            }
            cout << endl;
        } else if (c == 1) {
            for (int i = 0; i < r; i++) {
                cout << i + 2 << endl;
            }
        } else {
            for (int i = 1; i <= r; i++) {
                for (int j = r + 1; j <= r + c; j++) {
                    cout << i * j << " ";
                }
                cout << endl;
            }
        }
    }
}
