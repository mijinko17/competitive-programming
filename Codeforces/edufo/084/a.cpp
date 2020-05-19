#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lint n, k;
        cin >> n >> k;
        if (n >= k * k && (n - k * k) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
