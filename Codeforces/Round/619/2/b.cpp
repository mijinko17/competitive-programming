#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int M = -1, m = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                if (i - 1 >= 0 && a[i - 1] != -1) {
                    chmax(M, a[i - 1]);
                    chmin(m, a[i - 1]);
                }
                if (i + 1 < n && a[i + 1] != -1) {
                    chmax(M, a[i + 1]);
                    chmin(m, a[i + 1]);
                }
            }
        }
        if (M == -1 && m == INT_MAX) {
            cout << 0 << " " << 1 << endl;
            continue;
        }
        int k = (M + m) / 2;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = k;
            }
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            chmax(ans, abs(a[i] - a[i + 1]));
        }
        cout << ans << " " << k << endl;
    }
}
