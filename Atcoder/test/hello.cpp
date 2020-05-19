#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

int main() {
    lint mod = 1e+9 + 7;
    cout << pow_mod(2, 0, mod) << endl;
}
