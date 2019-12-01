#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int d, g;
    cin >> d >> g;
    g /= 100;
    vector<int> p(d), c(d);
    for (int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    int ans = INT_MAX;
    for (int i = 0; i < (1 << d); i++) {
        vector<bool> comp(d, false);
        int need = g;
        int q = 0;
        //コンプしたやつの処理
        for (int j = 0; j < d; j++) {
            if (i & (1 << j)) {
                need -= c[j] + p[j] * (j + 1);
                q += p[j];
                comp[j] = true;
            }
        }
        int now = d - 1;
        while (need > 0 && now >= 0) {
            if (!comp[now]) {
                int temp =
                    min((need + (now + 1) - 1) / ((now + 1)), p[now] - 1);
                q += temp;
                need -= temp * (now + 1);
            }
            now--;
        }
        if (need <= 0) {
            ans = min(ans, q);
        }
    }
    cout << ans << endl;
}
