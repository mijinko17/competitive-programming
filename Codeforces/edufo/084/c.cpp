#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m, k;
vector<pair<int, int>> s, f;

int main() {
    cin >> n >> m >> k;
    s.resize(k), f.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i].first >> s[i].second;
    }
    for (int i = 0; i < k; i++) {
        cin >> f[i].first >> f[i].second;
    }
    string ans = "";
    ans = ans + string(n - 1, 'U');
    ans = ans + string(m - 1, 'L');
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            ans += string(n - 1, 'D');
        } else {
            ans += string(n - 1, 'U');
        }
        if (i != m - 1) {
            ans += 'R';
        }
    }
    cout << ans.length() << endl;
    cout << ans << endl;
}
