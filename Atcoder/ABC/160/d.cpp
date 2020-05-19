#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, x, y;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int dist(int a, int b) {
    int ans = INT_MAX;
    chmin(ans, abs(a - b));
    chmin(ans, abs(a - x) + 1 + abs(y - b));
    chmin(ans, abs(a - y) + 1 + abs(x - b));
    return ans;
}

int main() {
    cin >> n >> x >> y;
    x--, y--;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans[dist(i, j)]++;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }
}
