#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int k, x;
    cin >> k >> x;
    string ans;
    if (k * 500 >= x) {
        ans = "Yes";
    } else {
        ans = "No";
    }
    cout << ans << endl;
}
