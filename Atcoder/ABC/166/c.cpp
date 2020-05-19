#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ただの辺
struct edge {
    int to;
    long long cost;
    // 引数一つの時は距離1
    edge(int t, long long c = 1) : to(t), cost(c) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool isGood = true;
        for (auto e : g[i]) {
            if (h[i] <= h[e.to]) {
                isGood = false;
                break;
            }
        }
        if (isGood) {
            ans++;
        }
    }
    cout << ans << endl;
}
