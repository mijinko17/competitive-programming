#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<bitset<64>> u, v;
vector<bool> s, t;

int main() {
    cin >> n;
    s.resize(n), t.resize(n);
    u.resize(n), v.resize(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp) {
            s[i] = true;
        } else {
            s[i] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp) {
            t[i] = true;
        } else {
            t[i] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        lint temp;
        cin >> temp;
        u[i] = bitset<64>(temp);
    }
    for (int i = 0; i < n; i++) {
        lint temp;
        cin >> temp;
        v[i] = bitset<64>(temp);
    }
    for (int z = 0; z < 64; z++) {
        int r0 = 0, r1 = 0, c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] && u[z] == 0) {
                r0++;
            }
            if (!s[i] && u[z] == 1) {
                r1++;
            }
            if (t[i] && v[z] == 0) {
                c0++;
            }
            if (!t[i] && v[z] == 1) {
                c1++;
            }
        }
        if (r1 > 0 && r0 > 0) {
            if (c0 > 0 || c1 > 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
}
