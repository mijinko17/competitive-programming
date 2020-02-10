#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == k + 1) {
            k++;
        }
    }
    int ans;
    if (k == 0) {
        ans = -1;
    } else {
        ans = n - k;
    }
    cout << ans << endl;
}
