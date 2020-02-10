#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= 3; i++) {
        if (i != a && i != b) {
            cout << i << endl;
            return 0;
        }
    }
}
