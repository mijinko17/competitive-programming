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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<edge>> g(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            g[i - a[i]].push_back(i);
        }
        if (i + a[i] < n) {
            g[i + a[i]].push_back(i);
        }
    }
    vector<int> ans(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        queue<int> bfs;
        bfs.push(i);
        int dist = 1;
        while (!bfs.empty()) {
            int now = bfs.front();
            bfs.pop();
            for (auto e : g[now]) {
                int next = e.to;
            }
        }
    }
}
