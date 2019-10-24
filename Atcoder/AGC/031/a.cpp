#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e+9 + 7;
    int n;
    string s;
    cin >> n >> s;
    vector<lint> abc(26, 1);
    for (int i = 0; i < n; i++) {
        abc[s[i] - 'a']++;
    }
    lint ans = 1;
    for (int i = 0; i < 26; i++) {
        ans *= abc[i];
        ans %= mod;
    }
    cout << ans - 1 << endl;
}
