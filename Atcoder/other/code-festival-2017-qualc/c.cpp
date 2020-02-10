#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string s;

int main() {
    cin >> s;
    string t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'x') {
            t.push_back(s[i]);
        }
    }
    int m = t.length();
    for (int i = 0; i < m - i - 1; i++) {
        if (t[i] != t[m - i - 1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int n = s.length();
    int left = 0, right = n - 1;
    int ans = 0;
    while (left < right) {
        if (s[left] != s[right]) {
            ans++;
            if (s[left] == 'x') {
                left++;
            } else {
                right--;
            }
        } else {
            left++, right--;
        }
    }
    cout << ans << endl;
}
