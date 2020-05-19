#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    t = t.substr(0, s.length());
    if (s == t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
