#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b, int c) {
    return abs(a - b) + abs(b - c);
}

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<int> s(a), t(b), x(q);
    for (int i = 0; i < a; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }
    int sl, sr, tl, tr;
    int sll, slr, srl, srr, tll, tlr, trl, trr;
    for (int i = 0; i < q; i++) {
        int ans = INT_MAX;
        //神社→寺
        sr = lower_bound(s.begin(), s.end(), x[i]) - s.begin();
        sl = sr--;
        if (sr < a) {
            trr = lower_bound(t.begin(), t.end(), s[sr]) - t.begin();
            trl = trr - 1;
            if (trr < b) {
                ans = min(ans, dist(x[i], s[sr], t[trr]));
            }
            if (trl >= 0) {
                ans = min(ans, dist(x[i], s[sr], t[trl]));
            }
        }
        if (sl >= 0) {
            tlr = lower_bound(t.begin(), t.end(), s[sl]) - t.begin();
            tll = tlr - 1;
            if (tlr < b) {
                ans = min(ans, dist(x[i], s[sl], t[tlr]));
            }
            if (tlr >= 0) {
                ans = min(ans, dist(x[i], s[sl], t[tll]));
            }
        }
        //寺→神社
        tr = lower_bound(t.begin(), t.end(), x[i]) - t.begin();
        tl = tr--;
        if (tr < b) {
            srr = lower_bound(s.begin(), s.end(), t[tr]) - s.begin();
            srl = srr - 1;
            if (srr < a) {
                ans = min(ans, dist(x[i], s[tr], t[srr]));
            }
            if (srl >= 0) {
                ans = min(ans, dist(x[i], s[tr], t[srl]));
            }
        }
        if (tl >= 0) {
            slr = lower_bound(s.begin(), s.end(), t[tl]) - s.begin();
            sll = slr - 1;
            if (slr < a) {
                ans = min(ans, dist(x[i], s[tl], t[slr]));
            }
            if (sll >= 0) {
                ans = min(ans, dist(x[i], s[tl], t[sll]));
            }
        }
        cout << sl << " " << sr << " " << tll << " " << tlr << " " << trl << " "
             << trr << endl;
        cout << tl << " " << tr << " " << sll << " " << slr << " " << srl << " "
             << srr << endl;
        cout << ans << endl;
    }
}
