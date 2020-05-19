#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int ans;
vector<bool> ab;
vector<bool> ac;
vector<bool> ba;
vector<bool> bc;
vector<bool> ca;
vector<bool> cb;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    string a, b, c;
    int l, m, n;
    cin >> a >> b >> c;
    l = a.length(), m = b.length(), n = c.length();
    ans = l + m + n;
    ab.assign(l, false);
    ac.assign(l, false);
    ba.assign(m, false);
    bc.assign(m, false);
    ca.assign(n, false);
    cb.assign(n, false);
    // a[i]~b[0]とできるか？
    for (int i = 0; i < l; i++) {
        int x = min(l - i, m);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (a[i + j] == '?' || b[j] == '?') {
                continue;
            } else {
                if (a[i + j] != b[j]) {
                    flag = false;
                    break;
                }
            }
        }
        ab[i] = flag;
    }
    // a[i]~c[0]とできるか？
    for (int i = 0; i < l; i++) {
        int x = min(l - i, n);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (a[i + j] == '?' || c[j] == '?') {
                continue;
            } else {
                if (a[i + j] != c[j]) {
                    flag = false;
                    break;
                }
            }
        }
        ac[i] = flag;
    }
    // b[i]~a[0]とできるか？
    for (int i = 0; i < m; i++) {
        int x = min(m - i, l);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (b[i + j] == '?' || a[j] == '?') {
                continue;
            } else {
                if (b[i + j] != a[j]) {
                    flag = false;
                    break;
                }
            }
        }
        ba[i] = flag;
    }
    // b[i]~c[0]とできるか？
    for (int i = 0; i < m; i++) {
        int x = min(m - i, n);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (b[i + j] == '?' || c[j] == '?') {
                continue;
            } else {
                if (b[i + j] != c[j]) {
                    flag = false;
                    break;
                }
            }
        }
        bc[i] = flag;
    }
    // c[i]~a[0]とできるか？
    for (int i = 0; i < n; i++) {
        int x = min(n - i, l);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (c[i + j] == '?' || a[j] == '?') {
                continue;
            } else {
                if (c[i + j] != a[j]) {
                    flag = false;
                    break;
                }
            }
        }
        ca[i] = flag;
    }
    // c[i]~b[0]とできるか？
    for (int i = 0; i < n; i++) {
        int x = min(n - i, m);
        bool flag = true;
        for (int j = 0; j < x; j++) {
            if (c[i + j] == '?' || b[j] == '?') {
                continue;
            } else {
                if (c[i + j] != b[j]) {
                    flag = false;
                    break;
                }
            }
        }
        cb[i] = flag;
    }
    // abc
    for (int i = 0; i < l; i++) {
        if (!ab[i]) continue;
        for (int j = 0; j < m; j++) {
            if (!bc[j]) continue;
            if (i + j < l && !ac[j]) continue;
            chmin(ans, max({l, i + m, i + j + n}));
        }
    }
    // acb
    for (int i = 0; i < l; i++) {
        if (!ac[i]) continue;
        for (int j = 0; j < n; j++) {
            if (!cb[j]) continue;
            if (i + j < l && !ab[j]) continue;
            chmin(ans, max({l, i + n, i + j + m}));
        }
    }
    // bac
    for (int i = 0; i < m; i++) {
        if (!ba[i]) continue;
        for (int j = 0; j < l; j++) {
            if (!ac[j]) continue;
            if (i + j < m && !bc[j]) continue;
            chmin(ans, max({m, i + l, i + j + n}));
        }
    }
    // bca
    for (int i = 0; i < m; i++) {
        if (!bc[i]) continue;
        for (int j = 0; j < n; j++) {
            if (!ca[j]) continue;
            if (i + j < m && !ba[j]) continue;
            chmin(ans, max({m, i + n, i + j + l}));
        }
    }
    // cab
    for (int i = 0; i < n; i++) {
        if (!ca[i]) continue;
        for (int j = 0; j < l; j++) {
            if (!ab[j]) continue;
            if (i + j < n && !cb[j]) continue;
            chmin(ans, max({n, i + l, i + j + m}));
        }
    }
    // cba
    for (int i = 0; i < n; i++) {
        if (!cb[i]) continue;
        for (int j = 0; j < m; j++) {
            if (!ba[j]) continue;
            if (i + j < n && !ca[j]) continue;
            chmin(ans, max({n, i + m, i + j + l}));
        }
    }
    cout << ans << endl;
}
