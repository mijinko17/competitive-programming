#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    lint ans = 0;
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == "ABC") {
            ans++;
        }
    }
    cout << ans << endl;
}
