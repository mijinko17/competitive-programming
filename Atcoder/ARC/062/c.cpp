#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n;
vector<lint> t, a;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin >> n;
    t.resize(n), a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }
    lint now_t = t[0], now_a = a[0];
    for (int i = 1; i < n; i++) {
    }
}
