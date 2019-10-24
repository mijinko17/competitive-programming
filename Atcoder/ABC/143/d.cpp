#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(all(l));
    lint ans = 0;
    // i:max
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            auto itr = lower_bound(all(l), l[j] - l[i] + 1);
            if (itr - l.begin() >= i) {
                continue;
            }
            ans += i - (itr - l.begin());
        }
    }
    cout << ans << endl;
}
