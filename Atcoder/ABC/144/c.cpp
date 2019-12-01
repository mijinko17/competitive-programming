#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n;
    cin >> n;
    lint ans = 1;
    for (lint i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = i;
        }
    }
    cout << ans + n / ans - 2 << endl;
}
