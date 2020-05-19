#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (1) {
        c -= b;
        if (c <= 0) {
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
        if (a <= 0) {
            cout << "No" << endl;
            return 0;
        }
    }
}
