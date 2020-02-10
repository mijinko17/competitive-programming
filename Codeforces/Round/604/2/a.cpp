#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

char next(char c) {
    if (c == 'a') {
        return 'b';
    } else if (c == 'b') {
        return 'c';
    } else {
        return 'a';
    }
}

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        bool flag = true;
        string s;
        cin >> s;
        int n = s.length();
        s = '#' + s + '#';
        for (int i = 1; i <= n; i++) {
            if (s[i] == '?') {
                if (s[i + 1] == '?') {
                    s[i] = next(s[i - 1]);
                } else {
                    if (s[i - 1] != 'a' && s[i + 1] != 'a') {
                        s[i] = 'a';
                    }
                    if (s[i - 1] != 'b' && s[i + 1] != 'b') {
                        s[i] = 'b';
                    }
                    if (s[i - 1] != 'c' && s[i + 1] != 'c') {
                        s[i] = 'c';
                    }
                }
            } else {
                if (s[i] == s[i + 1]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << s.substr(1, n) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
