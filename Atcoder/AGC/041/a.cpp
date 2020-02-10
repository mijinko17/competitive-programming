#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, a, b;
    cin >> n >> a >> b;
    lint ans;
    if ((b - a) % 2 == 0) {
        ans = (b - a) / 2;
    } else {
        lint c = min(a - 1, n - b);
        ans = c + 1 + (b - a - 1) / 2;
    }
    cout << ans << endl;
}
