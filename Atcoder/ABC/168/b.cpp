#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    string ans = "";
    if (s.length() <= k) {
        ans = s;
    } else {
        ans = s.substr(0, k) + "...";
    }
    cout << ans << endl;
}
