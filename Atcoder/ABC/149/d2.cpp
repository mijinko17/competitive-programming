#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, k, r, s, p;
string t;

char win(char c) {
    if (c == 'r')
        return s;
    else if (r == 's')
        return 'p';
    else
        return 'r';
}

char lose(char c) {
    return win(win(c));
}

int main() {
    cin >> n >> k >> r >> s >> p >> t;
    string ans(n, ' ');
    for (int i = 0; i < n; i++) {
        if (i < k || (i >= k && t[i - k] != t[i])) {
            ans = win(t[i]);
        } else {
            if (i + k < n) {
            }
        }
    }
}
