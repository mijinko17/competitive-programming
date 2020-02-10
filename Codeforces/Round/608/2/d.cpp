#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    unordered_map<int, int> sendable;
    for (int i = 0; i < n; i++) {
        sendable[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        sendable[]
    }
}
