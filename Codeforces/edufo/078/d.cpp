#include <bits/stdc++.h>
typedef long long lint;
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

// 辺の長さを無視した距離
// depend:edge
vector<long long> distance_nonweight(vector<vector<edge>>& g, int start) {
    vector<long long> res(g.size(), LLONG_MAX);
    res[start] = 0;
    queue<int> bfs;
    bfs.push(start);
    while (!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();
        for (auto e : g[now]) {
            int next = e.to;
            if (res[next] > res[now] + 1) {
                res[next] = res[now] + 1;
                bfs.push(next);
            }
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> event(2 * n + 1, 0);
    vector<int> left(n + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        event[l] = i;
        event[r] = -i;
        left[i] = l;
    }
    int num_edge = 0;
    vector<vector<edge>> g(n);
    set<pair<int, int>> s;
    for (int i = 0; i <= 2 * n; i++) {
        if (event[i] > 0) {
            s.insert({i, event[i]});
        }
        if (event[i] < 0) {
            int now = -event[i];
            auto target = s.lower_bound({left[now], INT_MIN});
            for (auto itr = next(target); itr != s.end(); itr++) {
                int next = itr->second;
                g[now - 1].push_back(edge(next - 1));
                g[next - 1].push_back(edge(now - 1));
                num_edge++;
            }
            if (num_edge >= n) {
                cout << "NO" << endl;
                return 0;
            }
            s.erase(target);
        }
    }
    if (num_edge != n - 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<lint> d = distance_nonweight(g, 0);
    for (int i = 0; i < n; i++) {
        if (d[i] == LLONG_MAX) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
