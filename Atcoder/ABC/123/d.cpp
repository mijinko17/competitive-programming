#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint x, y, z, k;
vector<lint> a, b, c;

//美味しさの合計がm以上なる組み合わせがいくつあるか
lint count(lint m) {
    lint res = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            lint now = a[i] + b[j];
            res += c.end() - lower_bound(c.begin(), c.end(), m - now);
        }
    }
    return res;
}

bool isvalid(lint m) {
    return count(m) >= k;
}

int main() {
    cin >> x >> y >> z >> k;
    a.resize(x);
    b.resize(y);
    c.resize(z);
    for (int i = 0; i < x; i++) cin >> a[i];
    for (int i = 0; i < y; i++) cin >> b[i];
    for (int i = 0; i < z; i++) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    lint ok = 0, no = LLONG_MAX / 2;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (isvalid(mid)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    vector<lint> ans;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            lint now = a[i] + b[j];
            auto bdry = upper_bound(c.begin(), c.end(), ok - now);
            for (auto itr = bdry; itr != c.end(); itr++) {
                ans.push_back(now + *itr);
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<lint>());
    for (auto e : ans) {
        cout << e << endl;
    }
    for (int i = 0; i < k - (lint)ans.size(); i++) {
        cout << ok << endl;
    }
}
