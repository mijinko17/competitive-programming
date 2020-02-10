#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    //-1:証言無し、0:不親切、1:正直
    vector<vector<int>> test(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            test[i][x] = y;
        }
    }
    int ans = 0;
    // i:bit
    for (int i = 0; i < (1 << n); i++) {
        bool flag = true;
        // j:ビット立ってる人
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                // k番目の人の情報
                for (int k = 0; k < n; k++) {
                    bool t1 = (test[j][k] == 0);
                    bool t2 = (test[j][k] == 1);
                    bool t3 = ((i & (1 << k)) == 0);
                    bool t4 = ((i & (1 << k)) > 0);
                    // cout << t1 << " " << t2 << " " << t3 << " " << t4 <<
                    // endl;
                    if ((t1 && t3) || (t2 && t4)) {
                    } else if (test[j][k] == -1) {
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            int temp = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp++;
                }
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;
}
