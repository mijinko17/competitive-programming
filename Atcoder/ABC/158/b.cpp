#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, a, b;

int main() {
    cin >> n >> a >> b;
    lint c = a + b;
    lint ans = 0;
    ans += (n / c) * a;
    n %= c;
    ans += min(a, n);
    cout << ans << endl;
}
