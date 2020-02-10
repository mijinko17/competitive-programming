#include <bits/stdc++.h>
typedef long long llong;
using namespace std;

int n;
llong k;
vector<llong> s;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> k;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i] == 0) {
            cout << n << endl;
            return 0;
        }
    }
    int ans = 0;
    llong product = 1;
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (product * s[r] <= k && r < n) {
            product *= s[r];
            r++;
        }
        chmax(ans, r - l);
        if (l == r) {
            r++;
        } else {
            product /= s[l];
        }
    }
    cout << ans << endl;
}
