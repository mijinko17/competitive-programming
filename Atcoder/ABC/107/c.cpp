#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x_m, x_p;
    x_p.push_back(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) {
            x_m.push_back(-x);
        } else if (x > 0) {
            x_p.push_back(x);
        } else {
            k--;
            if (k == 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    x_m.push_back(0);
    reverse(all(x_m));
    int ans = INT_MAX;
    //左からl個取ると思う
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        if (l >= x_m.size() || r >= x_p.size()) {
            continue;
        }
        int f = min(x_m[l], x_p[r]);
        int s = max(x_m[l], x_p[r]);
        ans = min(ans, f * 2 + s);
    }
    cout << ans << endl;
}
