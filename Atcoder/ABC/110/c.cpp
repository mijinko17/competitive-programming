#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    unordered_map<char, char> chara1, chara2;
    for (int i = 0; i < s.length(); i++) {
        if (chara1.count(s[i]) == 0) {
            chara1[s[i]] = t[i];
        } else {
            if (chara1[s[i]] != t[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < t.length(); i++) {
        if (chara2.count(t[i]) == 0) {
            chara2[t[i]] = s[i];
        } else {
            if (chara2[t[i]] != s[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
