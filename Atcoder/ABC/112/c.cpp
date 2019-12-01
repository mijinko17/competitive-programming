#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    int s_x, s_y, s_h;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i] != 0) s_x = x[i], s_y = y[i], s_h = h[i];
    }
    //中心を(i,j)と決め打つ
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int height = s_h + abs(i - s_x) + abs(j - s_y);
            bool isVarid = true;
            for (int k = 0; k < n; k++) {
                if (max(height - abs(x[k] - i) - abs(y[k] - j), 0) != h[k]) {
                    isVarid = false;
                    break;
                }
            }
            if (isVarid) {
                cout << i << " " << j << " " << height << endl;
                return 0;
            }
        }
    }
}
