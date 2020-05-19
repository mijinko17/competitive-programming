#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint x;
    cin >> x;
    lint ans = 0;
    ans += (x / 500) * 1000;
    x -= (x / 500) * 500;
    ans += (x / 5) * 5;
    cout << ans << endl;
}
