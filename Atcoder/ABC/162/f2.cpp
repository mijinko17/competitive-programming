#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

const int n = 27;
bool isvalid(bitset<n> b) {
    if (b.count() != n / 2) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == 1 && b[i + 1] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int hoge;
    cin >> hoge;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint ans = LLONG_MIN;
    for (int i = 0; i < (1 << 27); i++) {
        cout << i << endl;
        bitset<27> b(i);
        lint cand = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                cand += a[j];
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
}
