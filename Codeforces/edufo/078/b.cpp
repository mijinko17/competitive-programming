#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int a, b;
        cin >> a >> b;
        lint n = 0;
        while (n * (n + 1) / 2 < abs(a - b) ||
               (n * (n + 1) / 2 - abs(a - b)) % 2 != 0) {
            n++;
        }
        cout << n << endl;
    }
}
