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

int a, b, m;
vector<int> r, d;
vector<int> x, y, c;

int main() {
    cin >> a >> b >> m;
    r.resize(a), d.resize(b);
    for (int i = 0; i < a; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> d[i];
    }
    x.resize(m);
    y.resize(m);
    c.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--, y[i]--;
    }
    int mr = *min_element(r.begin(), r.end());
    int md = *min_element(d.begin(), d.end());
    int ans = INT_MAX;
    chmin(ans, mr + md);
    for (int i = 0; i < m; i++) {
        int cand = r[x[i]] + d[y[i]] - c[i];
        chmin(ans, cand);
    }
    cout << ans << endl;
}
