#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint game(lint init, vector<lint> &a) {
    for (int i = 0; i < a.size(); i++) {
        init -= init % a[i];
    }
    return init;
}

int main() {
    int k;
    cin >> k;
    vector<lint> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    //答えが2以上になる最小のやつ探す
    lint ok_b = 1e+18, no_b = 0;
    while (abs(ok_b - no_b) > 1) {
        lint mid = (ok_b + no_b) / 2;
        if (game(mid, a) >= 2) {
            ok_b = mid;
        } else {
            no_b = mid;
        }
    }
    //答えが2以下なる最大のやつ
    lint ok_t = 0, no_t = 1e+18;
    while (abs(ok_t - no_t) > 1) {
        lint mid = (ok_t + no_t) / 2;
        if (game(mid, a) <= 2) {
            ok_t = mid;
        } else {
            no_t = mid;
        }
    }
    if (game(ok_b, a) == 2 && game(ok_t, a) == 2 && ok_b <= ok_t) {
        cout << ok_b << " " << ok_t << endl;
    } else {
        cout << -1 << endl;
    }
}
