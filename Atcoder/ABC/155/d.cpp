#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;
vector<lint> a;

// m以下の積がk個以上あるかどうか
bool check(lint m) {
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (m >= 0) {
                ans += n - 1;
            }
        } else if (a[i] > 0) {
            lint pair = m / a[i];
            if (m < 0 && m % a[i] != 0) {
                pair--;
            }
            ans += upper_bound(a.begin(), a.end(), pair) - a.begin();
            if (a[i] * a[i] <= m) {
                ans--;
            }
        } else {
            lint pair = m / a[i];
            if (m < 0 && m % a[i] != 0) {
                pair++;
            }
            ans += a.end() - lower_bound(a.begin(), a.end(), pair);
            if (a[i] * a[i] <= m) {
                ans--;
            }
        }
    }
    ans /= 2;
    return ans >= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    lint ok = LLONG_MAX / 2, no = LLONG_MIN / 2;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (ok + no < 0 && (ok + no) % 2 != 0) {
            mid--;
        }
        // cout << mid << " " << check(mid) << endl;
        if (check(mid)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << ok << endl;
}
