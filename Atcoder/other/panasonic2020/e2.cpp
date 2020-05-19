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

vector<bool> x_y(string x, string y) {
    int p = x.length(), q = y.length();
    vector<bool> res(p + 1);
    // x[i]~y[0]とできるか？
    for (int i = 0; i < p; i++) {
        int m = min(p - i, q);
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (x[i + j] == '?' || y[j] == '?') continue;
            if (x[i + j] != y[j]) {
                flag = false;
                break;
            }
        }
        res[i] = flag;
    }
    res[p] = true;
    return res;
}

// x-y-zの順にくっつけるときの最短
int solve(string x, string y, string z) {
    int p = x.length(), q = y.length(), r = z.length();
    vector<bool> xy = x_y(x, y);
    vector<bool> yz = x_y(y, z);
    vector<bool> xz = x_y(x, z);
    int res = p + q + r;
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= q; j++) {
            if (!xy[i]) continue;
            if (!yz[j]) continue;
            if (i + j <= p && !xz[i + j]) continue;
            chmin(res, max({p, i + q, i + j + r}));
        }
    }
    return res;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int ans = INT_MAX;
    chmin(ans, solve(a, b, c));
    chmin(ans, solve(a, c, b));
    chmin(ans, solve(b, a, c));
    chmin(ans, solve(b, c, a));
    chmin(ans, solve(c, a, b));
    chmin(ans, solve(c, b, a));
    cout << ans << endl;
}
