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
    //範囲を(left,right]で管理
    lint left = -1, right = 1e+12;
    while (right - left > 1) {
        lint need = 0;
        lint mid = (left + right) / 2;
        for (int i = 0; i < n; i++) {
            // temp:必要なマンパワー
            lint temp = mid / f[i];
            need += max(a[i] - temp, (lint)0);
        }
        if (need <= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << endl;
}