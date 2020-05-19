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
    edge(int t, lint c = 1) : to(t), cost(c) {}
};

int n, m;
vector<vector<edge>> g;

bool check(int a, int b) {
    // front:now,back:from
    queue<pair<int, int>> bfs;
    bfs.push({a, -1});
    while (!bfs.empty()) {
        auto p = bfs.front();
        bfs.pop();
        for (auto e : g[p.first]) {
            if (e.to == p.second) continue;
            if (e.to == a) return true;
            if (e.to != b) {
                bfs.push({e.to, p.first});
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool has_six = false;
    vector<int> intersection;
    for (int i = 0; i < n; i++) {
        int s = g[i].size();
        if (s % 2 == 0) {
            if (s / 2 >= 3) {
                has_six = true;
            } else {
                if (s / 2 == 2) {
                    intersection.push_back(i);
                }
            }
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (has_six) {
        cout << "Yes" << endl;
        return 0;
    }
    string ans;
    int det = intersection.size();
    if (det > 2) {
        ans = "Yes";
    } else if (det == 2) {
        ans = (check(intersection[0], intersection[1]) ? "Yes" : "No");
    } else {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}
