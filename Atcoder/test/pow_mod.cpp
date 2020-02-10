#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 1e+9 + 7;
int n;
vector<lint> a;

//素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n != 1) res[n]++;
    return res;
}

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

// Z_pでのaの逆元を計算 O(log p)
// depend:pow_mod
long long inv_mod(long long a, long long p) {
    return pow_mod(a, p - 2, p);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<lint, lint> lcm;
    for (int i = 0; i < n; i++) {
        unordered_map<lint, lint> pf = pf_um(a[i]);
        for (auto e : pf) {
            if (lcm[e.first] < e.second) {
                lcm[e.first] = e.second;
            }
        }
    }
    lint l = 1;
    for (auto e : lcm) {
        l = l * pow_mod(e.first, e.second, mod) % mod;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        lint temp = l * inv_mod(a[i], mod);
        ans = (ans + temp) % mod;
    }
    cout << ans << endl;
}
