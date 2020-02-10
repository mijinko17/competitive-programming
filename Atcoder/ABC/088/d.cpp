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

int h, w;
vector<string> s;
vector<vector<edge>> g;

// 辺の長さを無視した距離
// depend:edge
vector<int> distance_nonweight(vector<vector<edge>> &g, int start) {
    vector<int> res(g.size(), INT_MAX);
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
    cin >> h >> w;
    s.resize(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    g.resize(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                if (i - 1 >= 0 && s[i - 1][j] == '.') {
                    g[i * w + j].push_back(edge((i - 1) * w + j));
                }
                if (i + 1 < h && s[i + 1][j] == '.') {
                    g[i * w + j].push_back(edge((i + 1) * w + j));
                }
                if (j - 1 >= 0 && s[i][j - 1] == '.') {
                    g[i * w + j].push_back(edge(i * w + j - 1));
                }
                if (j + 1 < w && s[i][j + 1] == '.') {
                    g[i * w + j].push_back(edge(i * w + j + 1));
                }
            }
        }
    }
    int sharp = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') sharp++;
        }
    }
    vector<int> dist = distance_nonweight(g, 0);
    int ans = 0;
    if (dist.back() == INT_MAX) {
        ans = -1;
    } else {
        ans = h * w - sharp - dist.back() - 1;
    }
    cout << ans << endl;
}
