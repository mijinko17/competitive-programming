#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, m, v, p;
vector<lint> a;

// a[i]をp位以内にできるか
bool check(lint cand) {
    lint modi = a[cand] + m;
    if (modi < a[n - p]) {
        return false;
    }
    lint l = cand + 1, r = n - p + 1;
    lint limit = 0;
    for (int i = l; i < r; i++) {
        limit += min(m, modi - a[i]);
    }
    return limit >= (v - l - n + r) * m;
}

int main() {
    cin >> n >> m >> v >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    lint ok = n - 1, no = -1;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (check(mid)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << n - ok << endl;
}
