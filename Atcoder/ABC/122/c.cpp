#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> cum(n + 1, 0);
    for (int i = 2; i < n + 1; i++) {
        cum[i] = cum[i - 1];
        if (s[i - 2] == 'A' && s[i - 1] == 'C') {
            cum[i]++;
        }
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << cum[r] - cum[l] << endl;
    }
}
