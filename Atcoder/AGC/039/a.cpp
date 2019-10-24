#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    lint k;
    cin >> s >> k;
    int n = s.length();
    string s1 = s + "#";
    string s2 = s + s + "#";
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (s[0] != s[i]) {
            break;
        }
        l = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[n - 1] != s[i]) {
            break;
        }
        r = i;
    }
    if (l >= r) {
        cout << (k * n) / 2 << endl;
        return 0;
    } else {
        int flag = 0;
        lint x = 0;
        for (int i = l + 1; i < r; i++) {
            if (s[i] == s[i + 1]) {
                flag++;
            }
            if (flag > 0 && s[i] != s[i + 1]) {
                x += (flag + 1) / 2;
                flag = 0;
            }
        }
        lint ans = 0;
        ans += (l + 1) / 2;
        ans += (n - r) / 2;
        ans += x * k;
        if (s[0] == s[n - 1]) {
            ans += (l + 1 + n - r) / 2 * (k - 1);
        } else {
            ans += ((l + 1) / 2 + (n - r) / 2) * (k - 1);
        }
        cout << ans << endl;
        return 0;
    }
}
