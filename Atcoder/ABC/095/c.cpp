#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int a, b, c, x, y;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> a >> b >> c >> x >> y;
    int ans = INT_MAX;
    // ABピザをi組買う
    for (int i = 0; i <= max(x, y); i++) {
        int cand = 2 * c * i;
        cand += max(0, x - i) * a;
        cand += max(0, y - i) * b;
        chmin(ans, cand);
    }
    cout << ans << endl;
}
