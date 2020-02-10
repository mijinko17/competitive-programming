#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

bool check(lint cand, lint m, lint v, lint p, vector<lint> a) {
    lint modified = a[cand] + m;
    lint up = a.end() - upper_bound(a.begin(), a.end(), modified);
    p -= up + 1;
    if (p < 0) {
        return false;
    }
    v -= cand + up;
    if (v <= 0) {
        return true;
    }
    lint ub = upper_bound(a.begin(), a.end(), modified) - a.begin();
    lint limit = 0;
    for (int i = cand + 1; i < ub - p; i++) {
        limit += min(modified - a[i], m);
    }
    return limit >= v * m;
}

bool check2(lint cand, lint m, lint v, lint p, vector<lint>& a) {
    lint n = a.size();
    if (n - cand <= p) {
        return true;
    }
    lint modi = a[cand] + m;
    // cout << a[n - p] << " " << modi << endl;
    if (a[n - p] > modi) {
        return false;
    }
    v -= p + cand;
    if (v <= 0) {
        return true;
    }
    lint limit = 0;
    for (int i = cand + 1; i < n - p + 1; i++) {
        //    cout << i << " " << min(modi - a[i], m) << endl;
        limit += min(modi - a[i], m);
    }
    // cout << "n-p+1:" << n - p + 1 << endl;
    // cout << "limit:" << limit << endl;
    return limit >= v * m;
}

int main() {
    lint n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    lint ok = n - 1, no = -1;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (check2(mid, m, v, p, a)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << n - ok << endl;
}
