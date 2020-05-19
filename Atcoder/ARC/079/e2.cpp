#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a;

bool isValid(lint m) {
    lint count = 0;
    for (int i = 0; i < n; i++) {
        lint b = max(0LL, a[i] + m - (n - 1));
        count += (b + n) / (n + 1);
    }
    return count <= m;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint ok = LLONG_MAX / 2, no = -1;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        (isValid(mid) ? ok : no) = mid;
    }
    for (lint i = max(0LL, ok - 1000000); i < ok + 1000000; i++) {
        if (isValid(i)) {
            cout << i << endl;
            return 0;
        }
    }
}
