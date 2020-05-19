#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> a, b;

int main() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int sa = a[0], sb = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        sa += a[i];
        sb = max(sb + b[i], sa + b[i]);
    }
    cout << sb << endl;
}
