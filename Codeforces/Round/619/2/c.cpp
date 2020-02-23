#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lint n, m;
        cin >> n >> m;
        lint k = n - m;
        lint small = k / (m + 1);
        lint large = small + 1;
        lint num_large = k % (m + 1);
        lint num_small = m + 1 - num_large;
        lint error = 0;
        error += small * (small + 1) / 2 * num_small + large * (large + 1) / 2 * num_large;
        cout << n * (n + 1) / 2 - error << endl;
    }
}
