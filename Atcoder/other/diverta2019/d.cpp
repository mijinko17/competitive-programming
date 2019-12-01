#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n;
    cin >> n;
    lint ans = 0;
    for (lint i = 1; i * (i + 1) < n; i++) {
        ans += n % i == 0 ? n / i - 1 : 0;
    }
    cout << ans << endl;
}
