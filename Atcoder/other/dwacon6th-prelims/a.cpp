#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<string> s;
vector<int> t;
string x;

int main() {
    cin >> n;
    s.resize(n);
    t.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    cin >> x;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == x) {
            start = i + 1;
            break;
        }
    }
    lint ans = 0;
    for (int i = start; i < n; i++) {
        ans += t[i];
    }
    cout << ans << endl;
}
