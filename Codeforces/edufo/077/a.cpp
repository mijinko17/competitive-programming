#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, s;
        cin >> c >> s;
        int v = s / c;
        int ans = v * v * (c - s % c) + (v + 1) * (v + 1) * (s % c);
        cout << ans << endl;
    }
}
