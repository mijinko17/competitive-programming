#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    string s(b - '0', a), t(a - '0', b);
    if (s <= t) {
        cout << s << endl;
    } else {
        cout << t << endl;
    }
}
