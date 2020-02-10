#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> a;
        vector<int> inv(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            inv[a[i] - 1] = i;
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int task = 0;
        int time = 0;
        int garbage = 0;
        vector<int> before(n);
        while (task < n) {
        }
    }
}
