#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b, k;
    cin >> k >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
}
