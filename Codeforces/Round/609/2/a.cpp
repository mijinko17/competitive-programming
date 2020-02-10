#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b;
    if (n == 1) {
        a = 9, b = 8;
    } else {
        a = 3 * n, b = 2 * n;
    }
    cout << a << " " << b << endl;
}
