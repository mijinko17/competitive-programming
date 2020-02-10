#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] /= 2;
    }
    lint l = 1;
    for (int i = 0; i < n; i++) {
        l = lcm(l, a[i]);
        if (l > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((l / a[i]) % 2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    lint ans = m / l - m / (2 * l);
    cout << ans << endl;
}
