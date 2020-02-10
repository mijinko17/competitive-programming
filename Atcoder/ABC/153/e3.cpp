#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint h, n;
vector<lint> a, b;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> h >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<lint> dp(h + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= h; j++) {
            if (dp[j] == LLONG_MAX) continue;
            chmin(dp[min(j + a[i], h)], dp[j] + b[i]);
        }
    }
    cout << dp[h] << endl;
}
