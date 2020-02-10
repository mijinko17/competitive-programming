#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    if (p > q) {
        swap(p, q);
    }
    lint ans = 0;
    while (p != q) {
        ans++;
        next_permutation(p.begin(), p.end());
    }
    cout << ans << endl;
}
