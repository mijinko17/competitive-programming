#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<lint> a(n);
    vector<lint> parity(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        parity[i % 2] += (a[i] + 1) / 2;
        parity[(i + 1) % 2] += a[i] / 2;
    }
    cout << min(parity[0], parity[1]) << endl;
}
