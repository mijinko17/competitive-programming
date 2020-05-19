#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint f(lint a, lint b) {
    return a * a * a * a * a - b * b * b * b * b;
}

int main() {
    lint x;
    cin >> x;
    lint limit = 3000;
    for (lint i = -limit; i <= limit; i++) {
        for (lint j = -limit; j <= limit; j++) {
            if (f(i, j) == x) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
}
