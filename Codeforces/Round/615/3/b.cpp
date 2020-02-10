#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> xy(n);
        for (int i = 0; i < n; i++) {
            cin >> xy[i].first >> xy[i].second;
        }
        sort(xy.begin(), xy.end());
        string ans = "";
        pair<int, int> now = {0, 0};
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int dx = xy[i].first - now.first, dy = xy[i].second - now.second;
            if (dx < 0 || dy < 0) {
                flag = false;
                break;
            } else {
                ans += string(dx, 'R') + string(dy, 'U');
                now = xy[i];
            }
        }
        if (flag) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
