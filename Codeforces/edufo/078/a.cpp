#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        string s, h;
        cin >> s >> h;
        sort(s.begin(), s.end());
        int n = s.length(), k = h.length();
        bool flag = false;
        for (int i = 0; i <= k - n; i++) {
            string cand = h.substr(i, n);
            sort(cand.begin(), cand.end());
            if (cand == s) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
