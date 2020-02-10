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

int main() {
    int n;
    cin >> n;
    vector<lint> c(n);
    lint even_min = INT_MAX, odd_min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (i % 2 == 1) {
            chmin(even_min, c[i]);
        } else {
            chmin(odd_min, c[i]);
        }
    }
    int q;
    cin >> q;
    lint ans = 0;
    lint even_num = n / 2, odd_num = n - even_num;
    lint even_bought = 0, odd_bought = 0;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            lint x, a;
            cin >> x >> a;
            x--;
            if (x % 2 == 1 && c[x] - even_bought - a >= 0) {
                ans += a;
                c[x] -= a;
                chmin(even_min, c[x]);
            } else if (x % 2 == 0 && c[x] - odd_bought - a >= 0) {
                ans += a;
                c[x] -= a;
                chmin(odd_min, c[x]);
            }
        } else if (type == 2) {
            lint a;
            cin >> a;
            if (odd_min - odd_bought - a >= 0) {
                ans += a * odd_num;
                odd_bought += a;
            }
        } else {
            lint a;
            cin >> a;
            if (odd_min - odd_bought - a >= 0 &&
                even_min - even_bought - a >= 0) {
                ans += a * n;
                odd_bought += a;
                even_bought += a;
            }
        }
    }
    cout << ans << endl;
}
