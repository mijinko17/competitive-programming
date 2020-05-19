#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 3; i++) {
        if (s[i] == '7') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
