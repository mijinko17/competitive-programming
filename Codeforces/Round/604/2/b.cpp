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
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        int n;
        cin >> n;
        // trans[i]:元の数列でのi+1の位置(0-indexed)
        vector<int> trans(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            trans[p - 1] = i;
        }
        int M = INT_MIN, m = INT_MAX;
        for (int i = 0; i < n; i++) {
            chmax(M, trans[i]);
            chmin(m, trans[i]);
            if (M - m == i) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}
