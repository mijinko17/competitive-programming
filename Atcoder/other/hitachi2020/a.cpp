#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 != 0) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && s[i] != 'h') {
            cout << "No" << endl;
            return 0;
        }
        if (i % 2 == 1 && s[i] != 'i') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
