#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int p, q;
        cin >> p >> q;
        vector<int> imos_x(q + 2), imos_y(q + 2);
        for (int i = 0; i < p; i++) {
            int x, y;
            char direction;
            cin >> x >> y >> direction;
            if (direction == 'N') {
                imos_y[y + 1] += 1;
            }
            if (direction == 'S') {
                imos_y[0] += 1;
                imos_y[y] -= 1;
            }
            if (direction == 'E') {
                imos_x[x + 1] += 1;
            }
            if (direction == 'W') {
                imos_x[0] += 1;
                imos_x[x] -= 1;
            }
        }
        vector<int> cum_x(q + 1, 0), cum_y(q + 1, 0);
        int now_x = 0;
        for (int i = 0; i <= q; i++) {
            now_x += imos_x[i];
            cum_x[i] = now_x;
        }
        int now_y = 0;
        for (int i = 0; i <= q; i++) {
            now_y += imos_y[i];
            cum_y[i] = now_y;
        }
        int m_x = *max_element(cum_x.begin(), cum_x.end());
        int m_y = *max_element(cum_y.begin(), cum_y.end());
        int ans_x = 0, ans_y = 0;
        for (int i = 0; i <= q; i++) {
            if (cum_x[i] == m_x) {
                ans_x = i;
                break;
            }
        }
        for (int i = 0; i <= q; i++) {
            if (cum_y[i] == m_y) {
                ans_y = i;
                break;
            }
        }
        cout << ans_x << ' ' << ans_y << endl;
    }
    return 0;
}
