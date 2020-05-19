#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, p;
string s;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

int main() {
    cin >> n >> p >> s;
    if (p == 2 || p == 5) {
        lint ans = 0;
        for (int i = 0; i < n; i++) {
            lint c = s[i] - '0';
            if (c % p == 0) {
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }
    lint sum = 0;
    map<lint, lint> count;
    count[0]++;
    for (int i = 0; i < n; i++) {
        int c = s[n - 1 - i] - '0';
        sum = sum + c * pow_mod(10, i, p);
        sum %= p;
        count[sum]++;
    }
    lint ans = 0;
    for (auto e : count) {
        lint temp = e.second;
        ans += temp * (temp - 1) / 2;
    }
    cout << ans << endl;
}
