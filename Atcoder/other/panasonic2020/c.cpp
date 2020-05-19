#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint a, b, c;
    cin >> a >> b >> c;
    lint d = c - a - b;
    if (d < 0) {
        cout << "No" << endl;
        return 0;
    }
    if (4 * a * b < d * d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
