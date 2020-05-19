#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        string s;
        cin >> s;
        int n = s.length();
        int depth = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            int now = s[i] - '0';
            if (now > depth) {
                ans += string(now - depth, '(');
            } else if (now < depth) {
                ans += string(depth - now, ')');
            }
            ans += s[i];
            depth = now;
        }
        if (depth != 0) {
            ans += string(depth, ')');
        }
        cout << ans << endl;
    }
    return 0;
}
