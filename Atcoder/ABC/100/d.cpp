#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int intl;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<intl>> val(8, vector<intl>(n));
    for (int i = 0; i < n; i++) {
        intl x, y, z;
        cin >> x >> y >> z;
        for (int j = 0; j < 8; j++) {
            intl tx = (j & (1 << 0)) ? x : -x;
            intl ty = (j & (1 << 1)) ? y : -y;
            intl tz = (j & (1 << 2)) ? z : -z;
            val[j][i] = tx + ty + tz;
        }
    }
    intl ans = INT_MIN;
    for (int i = 0; i < 8; i++) {
        sort(all(val[i]), greater<intl>());
        intl temp = 0;
        for (int j = 0; j < m; j++) {
            temp += val[i][j];
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
