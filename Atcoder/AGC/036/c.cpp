#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// a^n mod pを計算　O(log n)
long long int pow_p(long long int a, long long int n, long long int p) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = pow_p(a, n / 2, p);
        if (n % 2 == 0) {
            return (temp * temp) % p;
        } else {
            return (((temp * temp) % p) * a) % p;
        }
    }
}

// Z_pでのaの逆元を計算 O(log p)
long long int inv_p(long long int a, long long int p) {
    return pow_p(a, p - 2, p);
}

int main() {
    lint mod = 998244353;
    int n, k;
    cin >> n >> k;
    //階乗を用意
    vector<lint> factorial(3 * k + n);
    factorial[0] = 1;
    for (lint i = 1; i < 3 * k + n; i++) {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= mod;
    }
    //全体をansに入れておく
    lint ans;
    ans = factorial[3 * k + n - 1] * inv_p(factorial[n - 1], mod);
    ans %= mod;
    ans *= inv_p(factorial[3 * k], mod);
    ans %= mod;
    // maxがi>2*kなるやつ
    lint exclude_1 = 0;
    for (int i = 2 * k + 1; i <= 3 * k; i++) {
        lint temp = n;
        temp *= factorial[3 * k - i + n - 2];
        temp %= mod;
        temp *= inv_p(factorial[n - 2], mod);
        temp %= mod;
        temp *= inv_p(factorial[3 * k - i], mod);
        temp %= mod;
        exclude_1 += temp;
        exclude_1 %= mod;
    }
    // 1がi=k+1個以上あるやつ
    lint exclude_2 = 0;
    for (int i = k + 1; i <= n; i++) {
    }
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
    return 0;
}
