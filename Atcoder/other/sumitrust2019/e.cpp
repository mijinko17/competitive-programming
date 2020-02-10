#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint mod = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint ans = 1;
    vector<int> color(3, 0);
    for (int i = 0; i < n; i++) {
        lint cand = 0;
        int target = 0;
        for (int j = 0; j < 3; j++) {
            if (a[i] == color[j]) {
                cand++;
                target = j;
            }
        }
        ans = (ans * cand) % mod;
        color[target]++;
    }
    cout << ans << endl;
}
