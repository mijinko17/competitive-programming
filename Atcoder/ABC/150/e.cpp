#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

const lint mod = 1e+9 + 7;
lint n;
vector<lint> c;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

int main() {
    cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        lint add = c[i] * (n - i + 1) % mod;
        ans = (ans + add) % mod;
    }
    cout << ans * pow_mod(4, n - 1, mod) % mod << endl;
}
