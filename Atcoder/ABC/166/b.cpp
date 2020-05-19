#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> hasOkashi(n, false);
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            a--;
            hasOkashi[a] = true;
        }
    }
    int ans = 0;
    for (auto e : hasOkashi) {
        if (!e) {
            ans++;
        }
    }
    cout << ans << endl;
}
