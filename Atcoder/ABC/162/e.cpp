#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;
lint mod = 1e+9 + 7;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

// 素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long i = 2; i * i <= n; i++)
        while (n % i == 0) res[i]++, n /= i;
    if (n != 1) res[n]++;
    return res;
}

int main() {
    cin >> n >> k;
    // count[i]:gcdがiの倍数なるやつの個数
    vector<lint> count(k + 1);
    for (lint i = 1; i <= k; i++) {
        lint num = k / i;
        count[i] = pow_mod(num, n, mod);
    }
    for (lint i = k; i >= 1; i--) {
        auto div = divisor(i);
        for (auto e : div) {
            if (e == i) {
                continue;
            }
            count[e] = (count[e] - count[i]) % mod;
        }
    }
    lint ans = 0;
    for (lint i = 1; i <= k; i++) {
        ans = (ans + i * count[i]) % mod;
    }
    cout << ans << endl;
}
