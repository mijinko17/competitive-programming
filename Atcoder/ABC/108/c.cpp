#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    lint ans;
    if (k % 2 == 0) {
        // x:偶数、y:奇数
        lint x = n / k;
        lint y = n / (k / 2) - x;
        ans = x * x * x + y * y * y;
    } else {
        lint x = n / k;
        ans = x * x * x;
    }
    cout << ans << endl;
}
