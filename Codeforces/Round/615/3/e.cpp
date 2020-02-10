#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
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
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    lint ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> move(n, 0);
        for (int j = 0; j < n; j++) {
            if (a[j][i] > m * n) continue;
            if ((a[j][i] - i - 1) % m == 0) {
                int k = (a[j][i] - i - 1) / m;
                int rot = (j - k < 0) ? j - k + n : j - k;
                move[rot]++;
            }
        }
        int cost = n;
        for (int j = 0; j < n; j++) {
            chmin(cost, j + (n - move[j]));
        }
        ans += cost;
    }
    cout << ans << endl;
}
