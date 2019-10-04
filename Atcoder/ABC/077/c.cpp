#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    // bc[i]:b[i]の下に置けるcの数
    vector<lint> bc(n);
    for (int i = 0; i < n; i++) {
        bc[i] = c.end() - upper_bound(all(c), b[i]);
    }
    // sum_b[i]:=bc[i]~bc[n-1]の和
    vector<lint> sum_b(n);
    sum_b[n - 1] = bc[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        sum_b[i] = sum_b[i + 1] + bc[i];
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (upper_bound(all(b), a[i]) != b.end()) {
            ans += sum_b[upper_bound(all(b), a[i]) - b.begin()];
        }
    }
    cout << ans << endl;
    return 0;
}
