#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    lint k, n;
    cin >> k >> n;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint dist = (k - a[n - 1]) + a[0];
    for (int i = 0; i < n - 1; i++) {
        chmax(dist, a[i + 1] - a[i]);
    }
    cout << k - dist << endl;
}
