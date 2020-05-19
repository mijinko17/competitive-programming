#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int q;
lint a, b;

bool isvalid(lint m) {
    return (a * b - 1) / m != (a * b - 1) / (m + 1);
}

int main() {
    cin >> q;
    while (q--) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        // ok:ok,ok+1で競合が起きない
        lint ok = 0, no = LLONG_MAX / 2;
        while (abs(ok - no) > 1) {
            lint mid = (ok + no) / 2;
            (isvalid(mid) ? ok : no) = mid;
        }
        // cout << ok << endl;
        lint ans = 0;
        ans += min(ok, (a * b - 1) / (b + 1)) + b - 1;
        // cout << ans << endl;
        lint boundary = (a * b - 1) / (ok + 1);
        if (boundary > a) {
            ans += boundary - a;
        }
        if (boundary > b) {
            ans += boundary - b;
        }
        cout << ans << endl;
    }
}
