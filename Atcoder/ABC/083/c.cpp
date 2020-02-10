#include <bits/stdc++.h>
typedef long long llong;
using namespace std;

llong x, y;

int main() {
    cin >> x >> y;
    int ans = 0;
    while (x <= y) {
        x *= 2;
        ans++;
    }
    cout << ans << endl;
}
