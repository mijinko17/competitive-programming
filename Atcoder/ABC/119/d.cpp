#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int dist(int a, int b, int c) {
    return abs(a - b) + abs(b - c);
}

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<lint> s(a + 2);
    s[0] = LLONG_MIN;
    s[a + 1] = LLONG_MAX;
    for (int i = 1; i <= a; i++) {
        cin >> s[i];
    }
    vector<lint> t(a + 2);
    t[0] = LLONG_MIN;
    t[a + 1] = LLONG_MAX;
    for (int i = 1; i <= b; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < q; i++) {
        lint x;
        cin >> x;
        // shrine->temple
        int sl = *(lower_bound(s.begin(), s.end(), x) - 1);
    }
}
