#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int a, b, q;
vector<lint> s, t;

int main() {
    cin >> a >> b >> q;
    s.resize(a + 2), t.resize(b + 2);
    s.front() = t.front() = LLONG_MIN / 5;
    s.back() = t.back() = LLONG_MAX / 5;
    for (int i = 0; i < a; i++) {
        cin >> s[i + 1];
    }
    for (int i = 0; i < b; i++) {
        cin >> t[i + 1];
    }
    for (int i = 0; i < q; i++) {
        lint x;
        cin >> x;
        int near_shrine = lower_bound(s.begin(), s.end(), x) - s.begin();
        int near_temple = lower_bound(t.begin(), t.end(), x) - t.begin();
        lint ans = LLONG_MAX;
        for (int j = near_shrine - 1; j <= near_shrine; j++) {
            for (int k = near_temple - 1; k <= near_temple; k++) {
                chmin(ans, abs(x - s[j]) + abs(s[j] - t[k]));
                chmin(ans, abs(x - t[k]) + abs(t[k] - s[j]));
            }
        }
        cout << ans << endl;
    }
}
