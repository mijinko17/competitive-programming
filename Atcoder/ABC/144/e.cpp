#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    vector<lint> a(n), f(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    sort(all(a), greater<lint>());
    sort(all(f));
    lint cand_top = 1e+12, cand_bot = 0, cand_mid;
    while (cand_top > cand_bot) {
        lint need = 0;
        cand_mid = (cand_top + cand_bot) / 2;
        for (int i = 0; i < n; i++) {
            // temp:必要なマンパワー
            lint temp = cand_mid / f[i];
            need += max(a[i] - temp, (lint)0);
        }
        if (need <= k) {
            cand_top = cand_mid;
        } else {
            cand_bot = cand_mid;
        }
        if (cand_top - cand_bot <= 1) {
            break;
        }
    }
    // cand_botが実現できるか
    lint need = 0;
    for (int i = 0; i < n; i++) {
        // temp:必要なマンパワー
        lint temp = cand_bot / f[i];
        need += max(a[i] - temp, (lint)0);
    }
    if (need <= k) {
        cout << cand_bot << endl;
    } else {
        cout << cand_top << endl;
    }
}
