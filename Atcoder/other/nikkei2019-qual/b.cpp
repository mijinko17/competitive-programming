#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) {
            continue;
        } else if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
            ans++;
        } else {
            ans += 2;
        }
    }
    cout << ans << endl;
}
