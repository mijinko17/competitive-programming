#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int z = 0; z < q; z++) {
        string s;
        cin >> s;
        unordered_map<char, int> count;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }
        int u = min(count['U'], count['D']);
        int l = min(count['L'], count['R']);
        int ans;
        string sub;
        if (u * l != 0) {
            ans = (u + l) * 2;
            sub = string(l, 'R') + string(u, 'D') + string(l, 'L') +
                  string(u, 'U');
        } else if (u != 0) {
            ans = 2;
            sub = "UD";
        } else if (l != 0) {
            ans = 2;
            sub = "LR";
        } else {
            ans = 0;
            sub = "";
        }
        cout << ans << endl << sub << endl;
    }
}
