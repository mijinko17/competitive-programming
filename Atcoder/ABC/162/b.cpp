#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    lint ans = 0;
    for (lint i = 1; i <= n; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            ans += i;
        }
    }
    cout << ans << endl;
}
