#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

int main() {
    cin >> n;
    map<char, lint> count;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        count[s[0]]++;
    }
    lint ans = 0;
    vector<char> c{'M', 'A', 'R', 'C', 'H'};
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                ans += count[c[i]] * count[c[j]] * count[c[k]];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
