#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> power(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int tp, ts;
            cin >> tp >> ts;
            chmax(power[ts], tp);
        }
        for (int i = n - 1; i >= 0; i--) {
            chmax(power[i], power[i + 1]);
        }
        int now = 0;
        int ans = 0;
        while (now < n) {
            int reach = 0;
            int max_monster = 0;
            while (power[reach + 1] >= max(max_monster, a[now + reach]) &&
                   now + reach < n) {
                chmax(max_monster, a[now + reach]);
                reach++;
            }
            if (reach == 0) {
                ans = -1;
                break;
            }
            ans++;
            now += reach;
        }
        cout << ans << endl;
    }
}
