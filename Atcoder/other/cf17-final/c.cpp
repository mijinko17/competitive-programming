#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> d;

int gap(int a, int b) {
    if (a > b) swap(a, b);
    return min(b - a, 24 - (b - a));
}

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int ans;
    if (n >= 24) {
        ans = 0;
    } else {
        for (int i = 0; i < (1 << n); i++) {
            bitset<23> b(i);
            unordered_set<int> time;
            for (int j = 0; j < n; j++) {
                time.insert((b[j] ? d[j] : 24 - d[j]));
            }
            int ok = 12, no = -1;
            while (abs(ok - no) > 1) {
            }
        }
    }
}
