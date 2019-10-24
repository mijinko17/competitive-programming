#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    s = s + "#";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[i + 1]) {
            ans++;
        }
    }
    cout << ans << endl;
}
