#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int a, b, q;
vector<lint> s, t;

lint left_nearest(vector<lint>& v, lint k) {
    int ok = 0, no = v.size();
    while (abs(ok - no) > 1) {
        int mid = (ok + no) / 2;
        (v[mid] < k ? ok : no) = mid;
    }
    return v[ok];
}
lint right_nearest(vector<lint>& v, lint k) {
    int no = -1, ok = v.size() - 1;
    while (abs(ok - no) > 1) {
        int mid = (ok + no) / 2;
        (v[mid] > k ? ok : no) = mid;
    }
    return v[ok];
}

lint nearest(vector<lint>& v, lint k) {
    lint left = left_nearest(v, k), right = right_nearest(v, k);
    return abs(k - left) <= abs(k - right) ? left : right;
}

int main() {
    cin >> a >> b >> q;
    s.resize(a), t.resize(b);
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < q; i++) {
        lint x;
        cin >> x;
        lint ans = LLONG_MAX;
        //左神社
        lint ls1 = left_nearest(s, x);
        lint ls2 = nearest(t, ls1);
        chmin(ans, abs(x - ls1) + abs(ls1 - ls2));
        //右神社
        lint rs1 = right_nearest(s, x);
        lint rs2 = nearest(t, rs1);
        chmin(ans, abs(x - rs1) + abs(rs1 - rs2));
        //左寺
        lint lt1 = left_nearest(t, x);
        lint lt2 = nearest(s, lt1);
        chmin(ans, abs(x - lt1) + abs(lt1 - lt2));
        //右寺
        lint rt1 = right_nearest(t, x);
        lint rt2 = nearest(s, rt1);
        chmin(ans, abs(x - rt1) + abs(rt1 - rt2));
        cout << ans << endl;
    }
    return 0;
}
