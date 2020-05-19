#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    int M = max({a, b, c});
    int ans;
    if ((3 * M - a - b - c) % 2 == 0) {
        ans = (3 * M - a - b - c) / 2;
    } else {
        ans = (3 * (M + 1) - a - b - c) / 2;
    }
    cout << ans << endl;
}
