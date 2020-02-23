#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    lint ans = 0;
    while (n) {
        n /= k;
        ans++;
    }
    cout << ans << endl;
}
