#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<lint> a(n);
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 2) {
            ans += (a[i] - 1) / 2;
            a[i] -= ((a[i] - 1) / 2) * 2;
        }
    }
    a.push_back(0);
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            ans++;
        } else if (a[i] == 1) {
            if (a[i + 1] >= 1) {
                ans++;
                a[i]--;
                a[i + 1]--;
            }
        }
    }
    cout << ans << endl;
}
