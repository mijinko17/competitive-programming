#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        lint x;
        cin >> x;
        if (x % 14 > 0 && x % 14 <= 6 && x / 14 > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
