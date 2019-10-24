#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int m, k;
    cin >> m >> k;
    if (k > (1 << m) - 1) {
        cout << -1 << endl;
        return 0;
    }
    if (m == 1) {
        if (k == 0) {
            cout << "0 0 1 1 " << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        vector<int> ans(1 << (m + 1));
        for (int i = 0; i < (1 << m); i++) {
            ans[i] = i;
            ans[(1 << (m + 1)) - 2 - i] = i;
        }
        ans[(1 << m) - 1] = k;
        ans[(1 << (m + 1)) - 1] = k;
        ans[k] = (1 << m) - 1;
        ans[(1 << (m + 1)) - 2 - k] = (1 << m) - 1;
        for (int i = 0; i < (1 << (m + 1)); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
