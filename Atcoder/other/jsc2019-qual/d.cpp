#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e9 + 7;
    int n;
    string s;
    cin >> n >> s;
    if (s[0] != 'B' || s[2 * n - 1] != 'B') {
        cout << 0 << endl;
        return 0;
    }
    vector<int> t(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        t[i] = s[i] == 'W' ? 0 : 1;
    }
    string lr(2 * n, ' ');
    int num = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (num % 2 != t[i]) {
            lr[i] = 'L';
            num++;
        } else {
            lr[i] = 'R';
            num--;
            if (num < 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if (num != 0) {
        cout << 0 << endl;
        return 0;
    }
    lint numl = 0;
    lint ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * (i + 1)) % mod;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (lr[i] == 'L') {
            numl++;
        } else {
            ans = (ans * numl) % mod;
            numl--;
        }
    }
    cout << ans << endl;
}
