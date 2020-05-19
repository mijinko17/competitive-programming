#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, m;
    cin >> n >> m;
    if (n > m) swap(n, m);
    lint res;
    if (n == 1) {
        if (m == 1) {
            res = 1;
        } else {
            res = m - 2;
        }
    } else {
        res = (n - 2) * (m - 2);
    }
    cout << res << endl;
}
