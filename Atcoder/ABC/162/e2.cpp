#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n = 100;
    vector<int> count(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                int g = gcd(i, gcd(j, k));
                count[g]++;
                if (g == 14) {
                    cout << i << ' ' << j << ' ' << k << endl;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << count[i] << endl;
    }
}
