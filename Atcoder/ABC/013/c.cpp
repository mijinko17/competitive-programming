#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

lint n, h, a, b, c, d, e;

int main() {
    cin >> n >> h >> a >> b >> c >> d >> e;
    lint ans = LLONG_MAX;
    for (int i = 0; i <= n; i++) {
        lint l = n - i;
        lint m = max(0LL, (1 + e * l - h - b * i + d + e - 1) / (d + e));
        if (m > l) {
            continue;
        }
        chmin(ans, i * a + m * c);
        if (ans == 600) {
            cout << i << " " << m << endl;
        }
    }
    cout << ans << endl;
}
