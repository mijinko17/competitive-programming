#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 1e+9 + 7;
int n;
vector<lint> a;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long int lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// a^n mod pを計算　O(log n)
long long int pow_mod(long long int a, long long int n, long long int p) {
    if (n == 0) return 1;
    long long int temp = pow_mod(a, n / 2, p);
    return n & 1 ? (((temp * temp) % p) * a) % p : (temp * temp) % p;
}

// Z_pでのaの逆元を計算 O(log p)
// depend:pow_mod
long long int inv_mod(long long int a, long long int p) {
    return pow_mod(a, p - 2, p);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint l = 1;
    for (int i = 0; i < n; i++) {
        l = lcm(l, a[i]);
        l %= mod;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (l * inv_mod(a[i], mod)) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
