#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 1e+9 + 7;
string s;

int main() {
    cin >> s;
    int n = s.length();
    lint a = 0, ab = 0, abc = 0;
    lint pattern = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a = (a + pattern) % mod;
        } else if (s[i] == 'B') {
            ab = (ab + a) % mod;
        } else if (s[i] == 'C') {
            abc = (abc + ab) % mod;
        } else {
            abc = (ab + abc * 3) % mod;
            ab = (ab * 3 + a) % mod;
            a = (a * 3 + pattern) % mod;
            pattern = pattern * 3 % mod;
        }
    }
    cout << abc << endl;
}
