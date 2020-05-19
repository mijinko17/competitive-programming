#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    for (int i = 1; i <= 20000; i++) {
        int x = i * 8 / 100, y = i * 10 / 100;
        if (x == a && y == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
