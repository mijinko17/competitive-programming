#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n = 2;
    string ans = "";
    for (int i = 0; i < 100; i++) {
        string s = to_string(i);
        s = string(2 - s.length(), '0') + s;
        ans += s;
    }
    cout << ans << endl;
}
