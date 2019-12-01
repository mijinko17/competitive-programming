#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    lint n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    // a=0としたい
    b = b - a;
    // i:プラスの数
    for (lint p = 0; p < n - 1; p++) {
        lint q = n - 1 - p;
        lint M = d * p - c * q, m = c * p - d * q;
        if (b >= m && b <= M) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
