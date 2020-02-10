#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.length() != 3) {
        cout << "error" << endl;
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        if (s[i] - '0' < 0 || s[i] - '0' >= 10) {
            cout << "error" << endl;
            return 0;
        }
    }
    int n = stoi(s);
    cout << 2 * n << endl;
}
