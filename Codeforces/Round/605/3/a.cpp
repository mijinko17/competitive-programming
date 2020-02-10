#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int z = 0; z < q; z++) {
        vector<int> x(3);
        for (int i = 0; i < 3; i++) {
            cin >> x[i];
        }
        sort(x.begin(), x.end());
        int ans = max(0, 2 * (x[2] - x[0] - 2));
        cout << ans << endl;
    }
}
