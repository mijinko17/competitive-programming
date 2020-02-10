#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> testimony(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            testimony[i][x] = y;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bitset<15> bit(i);
        bool flag = true;
        for (int j = 0; j < n && flag; j++) {
            if (!bit[j]) continue;
            for (int k = 0; k < n; k++) {
                if (testimony[j][k] == -1) continue;
                if (bit[k] != testimony[j][k]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) ans = max(ans, (int)bit.count());
    }
    cout << ans << endl;
    return 0;
}
