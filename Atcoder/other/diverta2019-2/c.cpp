#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int num_minus = lower_bound(all(a), 0) - a.begin();
    int minus_part, plus_part;
    if (num_minus >= n - 1) {
        minus_part = n - 2;
        plus_part = 0;
    } else if (num_minus >= 1) {
        minus_part = num_minus - 1;
        plus_part = n - num_minus - 1;
    } else {
        minus_part = 0;
        plus_part = n - 2;
    }
    //最大値を先に求める
    int ans = a[n - 1] - a[0];
    for (int i = 1; i < n - 1; i++) {
        if (i <= minus_part) {
            ans -= a[i];
        } else {
            ans += a[i];
        }
    }
    cout << ans << endl;
    //(p-q)-(r-s)としたい
    int p = a[n - 1], r = a[0];
    queue<int> q, s;
    for (int i = 1; i <= minus_part; i++) {
        q.push(a[i]);
    }
    for (int i = minus_part + 1; i < n - 1; i++) {
        s.push(a[i]);
    }
    // p-q
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << p << " " << now << endl;
        p = p - now;
    }
    // r-s
    while (!s.empty()) {
        int now = s.front();
        s.pop();
        cout << r << " " << now << endl;
        r = r - now;
    }
    //(p-q)-(r-s)
    cout << p << " " << r << endl;
}
