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

int n;
vector<vector<edge>> g;

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    auto d = distance_nonweight(g, 0);
    int num_even = 0, num_odd = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] % 2 == 0) {
            num_even++;
        } else {
            num_odd++;
        }
    }
    vector<int> ans(n, -1);
    int num_0 = n / 3;
    int num_1 = n / 3 + ((n % 3 > 0) ? 1 : 0);
    int num_2 = n / 3 + ((n % 3 > 1) ? 1 : 0);
    if ((num_even >= num_1 && num_odd >= num_2) || (num_even >= num_2 && num_odd >= num_1)) {
        if (num_even >= num_1 && num_odd >= num_2) {
            for (int i = 0; i < n; i++) {
                if (d[i] % 2 == 0) {
                    ans[i] = 1;
                } else {
                    ans[i] = 2;
                }
            }
        } else if (num_even >= num_2 && num_odd >= num_1) {
            for (int i = 0; i < n; i++) {
                if (d[i] % 2 == 0) {
                    ans[i] = 2;
                } else {
                    ans[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) {
                if (num_1) {
                    num_1--;
                } else {
                    ans[i] = 0;
                }
            } else if (ans[i] == 2) {
                if (num_2) {
                    num_2--;
                } else {
                    ans[i] = 0;
                }
            }
        }
    } else {
        if (num_even <= num_0) {
            for (int i = 0; i < n; i++) {
                if (d[i] % 2 == 0) {
                    ans[i] = 0;
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (d[i] % 2 == 1) {
                    ans[i] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] != 0) {
                if (num_1) {
                    ans[i] = 1;
                    num_1--;
                } else if (num_2) {
                    ans[i] = 2;
                    num_2--;
                } else {
                    ans[i] = 0;
                }
            }
        }
    }
    int a = 1, b = 2, c = 3;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            cout << c << endl;
            c += 3;
        } else if (ans[i] == 1) {
            cout << a << endl;
            a += 3;
        } else {
            cout << b << endl;
            b += 3;
        }
    }
}
