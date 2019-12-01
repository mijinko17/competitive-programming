#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//ただの辺
struct edge {
    using lint = long long int;
    int to;
    lint cost;
    //引数一つの時は距離1
    edge(int t, lint c = 1) : to(t), cost(c) {
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<edge>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(edge(b));
        g[b].push_back(edge(a));
    }
    lint ans = 0;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ans += c[i];
    }
    sort(all(c));
    ans -= c[n - 1];
    queue<int> q;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        deg[i] = g[i].size();
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    vector<int> w(n);
    auto itr = c.begin();
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        w[now] = (*itr);
        itr++;
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i].to;
            deg[next]--;
            if (deg[next] == 1) {
                q.push(next);
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << w[i] << " ";
    }
    cout << endl;
}
