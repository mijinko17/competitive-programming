#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, x;
    cin >> n >> x;
    lint ans = 0;
    //とりあえず二回進む
    ans += n;
    lint p = max(x, n - x), q = min(x, n - x);
    //終わる直前まで進める
    while (p % q != 0) {
        ans += (p / q) * q * 2;
        p = p % q;
        swap(p, q);
    }
    //最後は2*p/q-1回進む
    ans += (p / q * 2 - 1) * q;
    cout << ans << endl;
    return 0;
}
