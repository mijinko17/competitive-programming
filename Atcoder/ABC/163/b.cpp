#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, m;
    cin >> n >> m;
    lint a = 0;
    for (int i = 0; i < m; i++) {
        lint t;
        cin >> t;
        a += t;
    }
    if (a <= n) {
        cout << n - a << endl;
    } else {
        cout << -1 << endl;
    }
}
