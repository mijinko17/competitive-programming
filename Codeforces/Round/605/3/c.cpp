#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, k;
    string s;
    cin >> n >> k >> s;
    unordered_set<char> usable;
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        usable.insert(c);
    }
    lint length = 0;
    lint ans = 0;
    s = s + '#';
    for (int i = 0; i < s.length(); i++) {
        if (usable.count(s[i])) {
            length++;
        } else {
            ans += length * (length + 1) / 2;
            length = 0;
        }
    }
    cout << ans << endl;
}
