#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 1e+9 + 7;
int n;
vector<lint> a;

// 素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long i = 2; i * i <= n; i++)
        while (n % i == 0) res[i]++, n /= i;
    if (n != 1) res[n]++;
    return res;
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

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<lint, lint> lcm;
    for (int i = 0; i < n; i++) {
        auto pf = pf_um(a[i]);
        for (auto e : pf) {
            chmax(lcm[e.first], e.second);
        }
    }
    lint l = 1;
    for (auto e : lcm) {
        l = l * pow_mod(e.first, e.second, mod) % mod;
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        lint temp = l * inv_mod(a[i], mod) % mod;
        ans = (ans + temp) % mod;
    }
    cout << ans << endl;
}
