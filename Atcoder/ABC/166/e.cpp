#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n;
vector<lint> a;

int main() {
    cin >> n;
    a.resize(n);
    for (lint i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<lint> b(n), c(n);
    for (lint i = 0; i < n; i++) {
        b[i] = a[i] + i;
        c[i] = i - a[i];
    }
    map<lint, lint> count;
    count[b[0]]++;
    lint ans = 0;
    for (lint i = 1; i < n; i++) {
        ans += count[c[i]];
        count[b[i]]++;
    }
    cout << ans << endl;
}
