#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> xy(n);
    for (int i = 0; i < n; i++) {
        cin >> xy[i].first >> xy[i].second;
    }
    sort(all(xy));
    lint ans = LLONG_MAX;
    // l:左
    for (int l = 0; l < n; l++) {
        // r:右
        for (int r = l + 1; r < n; r++) {
            // u:上
            for (int u = l; u <= r; u++) {
                // d:下
                for (int d = l; d <= r; d++) {
                    if (xy[u].second < xy[d].second) continue;
                    int num = 0;
                    lint top = xy[u].second, bottom = xy[d].second;
                    lint left = xy[l].first, right = xy[r].first;
                    for (int m = l; m <= r; m++) {
                        if (xy[m].second >= bottom && xy[m].second <= top) {
                            num++;
                        }
                    }
                    if (num >= k) {
                        ans = min(ans, (top - bottom) * (right - left));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
