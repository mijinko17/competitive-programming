#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// a^n mod pを計算　O(log n)
long long int pow_mod(long long int a, long long int n, long long int p) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = pow_mod(a, n / 2, p);
        return n & 1 ? (((temp * temp) % p) * a) % p : (temp * temp) % p;
    }
}

// Z_pでのaの逆元を計算 O(log p)
// depend:pow_mod
long long int inv_mod(long long int a, long long int p) {
    return pow_mod(a, p - 2, p);
}

int main() {
    lint mod = 998244353;
    int n;
    cin >> n;
    vector<lint> d(n, 0);
    int d0;
    cin >> d0;
    if (d0 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int d_max = 0;
    for (int i = 0; i < n - 1; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            cout << 0 << endl;
            return 0;
        }
        d[temp]++;
        d_max = max(d_max, temp);
    }
    lint ans = 1;
    for (int i = 2; i <= d_max; i++) {
        ans *= pow_mod(d[i - 1], d[i], mod);
        ans %= mod;
    }
    cout << ans << endl;
}
