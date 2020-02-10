#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    lint n;
    cin >> n;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<lint> bit(60, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 60; j++) {
            if (a[i] & (1LL << j)) {
                bit[j]++;
            }
        }
    }
    lint ans = 0;
    int pow = 1;
    for (int i = 0; i < 60; i++) {
        lint comb = bit[i] * (n - bit[i]);
        comb %= mod;
        ans += comb * pow;
        ans %= mod;
        pow = (pow * 2) % mod;
    }
    cout << ans << endl;
}
