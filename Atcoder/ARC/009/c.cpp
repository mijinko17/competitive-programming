#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;

int main() {
    cin >> n >> k;
    vector<lint> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    lint ans = 0;
    do {
        int diff = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] != i) {
                diff++;
            }
        }
        if (diff == k) {
            ans++;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}
