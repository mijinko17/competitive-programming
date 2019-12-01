#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

void no() {
    cout << -1 << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (a[0] != 0) {
        no();
        return 0;
    };
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] > 1) {
            no();
            return 0;
        }
    }
    lint ans = 0;
    int now = n - 1;
    while (now > 0) {
        ans += a[now];
        while (a[now] - a[now - 1] == 1) {
            now--;
        }
        now--;
    }
    cout << ans << endl;
}
