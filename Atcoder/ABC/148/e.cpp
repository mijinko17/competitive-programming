#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint num_fac(lint n, lint p) {
    lint res = 0;
    lint pow = p;
    while (n / pow) {
        res += n / pow;
        pow *= p;
    }
    return res;
}

int main() {
    lint n;
    cin >> n;
    lint ans;
    if (n % 2 == 0) {
        lint k = n / 2;
        lint a = num_fac(k, 2) + k;
        lint b = num_fac(k, 5);
        ans = min(a, b);
    } else {
        ans = 0;
    }
    cout << ans << endl;
}
