#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m, x;
vector<int> c;
vector<vector<int>> a;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> m >> x;
    c.resize(n);
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        bitset<12> b(i);
        vector<int> rikai(m, 0);
        int sum_c = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                sum_c += c[j];
                for (int k = 0; k < m; k++) {
                    rikai[k] += a[j][k];
                }
            }
        }
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (rikai[j] < x) {
                flag = false;
                break;
            }
        }
        if (flag) {
            chmin(ans, sum_c);
        }
    }
    if (ans != INT_MAX) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}
