#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, a, b;
    cin >> n >> a >> b;
    lint ans;
    if (n == 1) {
        ans = a == b ? 1 : 0;
    } else {
        if (a > b) {
            ans = 0;
        } else if (a == b) {
            ans = 1;
        } else {
            ans = a + (n - 1) * b - (a * (n - 1) + b) + 1;
        }
    }
    cout << ans << endl;
}
