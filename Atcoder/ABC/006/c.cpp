#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    m -= 2 * n;
    int baby = 0, elder = 0;
    for (int i = 0; i < n; i++) {
        if (m > 1) {
            m -= 2;
            baby++;
        } else if (m == 1) {
            m -= 1;
            elder++;
        }
    }
    if (m == 0) {
        cout << n - baby - elder << " " << elder << " " << baby << endl;
    } else {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
}
