#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> p;

int main() {
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int ans = 1;
    int minimum = p[0];
    for (int i = 1; i < n; i++) {
        if (p[i] <= minimum) {
            ans++;
            minimum = p[i];
        }
    }
    cout << ans << endl;
}
