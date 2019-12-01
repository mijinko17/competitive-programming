#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    vector<int> trans(26, -1);
    //変換表を作る
    for (int i = 0; i < n; i++) {
        if (trans[s[i] - 'a'] < 0) {
            trans[s[i] - 'a'] = t[i] - 'a';
        } else {
            if (trans[s[i] - 'a'] != t[i] - 'a') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    //単射か確認
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (trans[i] == trans[j] && trans[i] != -1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
