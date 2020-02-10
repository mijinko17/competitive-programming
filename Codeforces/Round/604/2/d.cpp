#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == 0 && b == 0) {
        if (abs(c - d) <= 1) {
            cout << "YES" << endl;
            if (c < d) {
                cout << "3 ";
                d--;
            }
            for (int i = 0; i < d; i++) {
                cout << "2 3 ";
            }
            if (c > d) {
                cout << "2 ";
            }
            cout << endl;
        }
    } else if (c == 0 && d == 0) {
        if (abs(a - b) <= 1) {
            cout << "YES" << endl;
            if (c < d) {
                cout << "0 ";
                d--;
            }
            for (int i = 0; i < d; i++) {
                cout << "2 3 ";
            }
            if (c > d) {
                cout << "2 ";
            }
            cout << endl;
        }
    }
    {}
    b -= a;
    c -= d;
    if (b < 0 || c < 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (abs(b - c) > 1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (b > c) {
        cout << "1 ";
        b--;
    }
    for (int i = 0; i < a; i++) {
        cout << "0 1 ";
    }
    for (int i = 0; i < b; i++) {
        cout << "2 1 ";
    }
    for (int i = 0; i < d; i++) {
        cout << "2 3 ";
    }
    if (c > b) {
        cout << "2 ";
    }
    cout << endl;
}
