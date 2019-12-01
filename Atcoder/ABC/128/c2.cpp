#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    // input
    int n, m;
    cin >> n >> m;
    //スイッチごとにどの電球に繋がってるかbitで管理
    vector<int> sw(n, 0);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            cin >> s;
            s--;
            sw[s] |= (1 << i);
        }
    }
    //点灯条件をbitで管理
    int p = 0;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        p |= (1 << i) * temp;
    }
    // input終わり

    // bit全探索
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        int state = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                state ^= sw[j];
            }
        }
        if (state == p) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
