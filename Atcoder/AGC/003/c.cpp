#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i % 2;
    }
    sort(all(a));
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (a[2 * i + 1].second == 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
