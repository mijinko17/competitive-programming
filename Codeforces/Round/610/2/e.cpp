#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct triangle {
    vector<int> vertex;
    triangle(int a = 0, int b = 0, int c = 0) {
        vertex.resize(3);
        vertex[0] = a, vertex[1] = b, vertex[2] = c;
        sort(vertex.begin(), vertex.end());
    }
};

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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<triangle> tri(n);
        vector<set<int>> l(n);
        map<pair<int, int>, int> count;
        for (int i = 0; i < n - 2; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--, c--;
            tri[i] = triangle(a, b, c);
            count[{min(a, b), max(a, b)}]++;
            count[{min(b, c), max(b, c)}]++;
            count[{min(c, a), max(c, a)}]++;
            l[a].insert(i);
            l[b].insert(i);
            l[c].insert(i);
        }
        // 辺の順序
        vector<vector<edge>> g(n);
        for (auto e : count) {
            if (e.second == 1) {
                int a = e.first.first, b = e.first.second;
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
        int now = 0, from = g[0][0].to;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = now;
            for (auto e : g[now]) {
                if (e.to != from) {
                    from = now;
                    now = e.to;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;
        // 切り分けの順番
        queue<int> bfs;
        for (int i = 0; i < n; i++) {
            if (l[i].size() == 1) bfs.push(i);
        }
        vector<int> q;
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            // target:消す三角形
            int target = *l[v].begin();
            q.push_back(target);
            for (auto e : tri[target].vertex) {
                l[e].erase(target);
                if (l[e].size() == 1) bfs.push(e);
            }
        }
        for (int i = 0; i < n - 2; i++) {
            cout << q[i] + 1 << " ";
        }
        cout << endl;
    }
}
