#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint sum_perm(lint f, lint num) {
    return num * (num + 2 * f - 1) / 2;
}
lint sum_perm2(lint f, lint num, lint diff) {
    return num * (num * diff + 2 * f - diff) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        lint l, r;
        cin >> l >> r;
        lint ans = 0;
        if (l >= r) {
            lint ok = 1e+10, no = 0;
            while (abs(ok - no) > 1) {
                lint mid = (ok + no) / 2;
                if (l - sum_perm(1, mid) < r) {
                    ok = mid;
                } else {
                    no = mid;
                }
            }
            l -= sum_perm(1, ok);
            ans += ok;
        } else {
            lint ok = 1e+10, no = 0;
            while (abs(ok - no) > 1) {
                lint mid = (ok + no) / 2;
                if (r - sum_perm(1, mid) <= l) {
                    ok = mid;
                } else {
                    no = mid;
                }
            }
            r -= sum_perm(1, ok);
            ans += ok;
        }
        while (1) {
            if (l >= r) {
                lint ok = 0, no = 1e+10;
                while (abs(ok - no) > 1) {
                    lint mid = (ok + no) / 2;
                    lint ll = l - sum_perm2(ans + 1, mid + 1, 2);
                    lint rr = r - sum_perm2(ans + 2, mid, 2);
                    if (ll >= 0 && ll < rr) {
                        ok = mid;
                    } else {
                        no = mid;
                    }
                }
            }
        }
    }
    return 0;
}
