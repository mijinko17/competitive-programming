#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint x, y, a, b, c;
vector<lint> p, q, r;

int main() {
    cin >> x >> y >> a >> b >> c;
    p.resize(a), q.resize(b), r.resize(c);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> r[i];
    }
    sort(p.begin(), p.end(), greater<lint>());
    sort(q.begin(), q.end(), greater<lint>());
    sort(r.begin(), r.end(), greater<lint>());
    vector<lint> greed;
    for (int i = 0; i < x; i++) {
        greed.push_back(p[i]);
    }
    for (int i = 0; i < y; i++) {
        greed.push_back(q[i]);
    }
    for (int i = 0; i < c; i++) {
        greed.push_back(r[i]);
    }
    sort(greed.begin(), greed.end(), greater<lint>());
    lint ans = 0;
    for (int i = 0; i < x + y; i++) {
        ans += greed[i];
    }
    cout << ans << endl;
}
