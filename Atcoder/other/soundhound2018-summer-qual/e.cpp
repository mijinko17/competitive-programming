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
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    unordered_map<int, unordered_map<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v, s;
        cin >> u >> v >> s;
        u--, v--;
        g[u].push_back(edge(v, s));
        g[v].push_back(edge(u, s));
        e[u][v] = s;
        e[v][u] = s;
    }
    //二部グラフか判定しつつ奇閉路を検出
    // bfs的にどこから来たか　<0の時はまだ来てない
    vector<int> from(n, -1);
    from[0] = 0;
    // 01割り当て
    vector<int> bipartite(n);
    bipartite[0] = 0;
    queue<int> q;
    q.push(0);
    //奇閉路の端点のうち二部グラフの割り当てが偶数or奇数
    int cycle_odd = -1, cycle_even = -1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i].to;
            if (bipartite[next] < 0) {
                bipartite[next] = 1 - bipartite[now];
                from[next] = now;
                q.push(next);
            } else {
                if (bipartite[next] == bipartite[now]) {
                    cycle_odd = now, cycle_even = next;
                    break;
                }
            }
        }
    }
    if (cycle_odd < 0) {  //二部グラフの時
        // bfs的に数字割り当て
        queue<int> r;
        r.push(0);
        vector<int> test_s(n, INT_MAX);
        test_s[0] = 1;
        int odd_min = INT_MAX, even_min = 1;
        while (!r.empty()) {
            int now = r.front();
            r.pop();
            for (int i = 0; i < g[now].size(); i++) {
                int next = g[now][i].to;
                if (test_s[next] == INT_MAX) {
                    test_s[next] = g[now][i].cost - test_s[now];
                    if (bipartite[next] == 0) {
                        even_min = min(even_min, test_s[next]);
                    } else {
                        odd_min = min(odd_min, test_s[next]);
                    }
                    r.push(next);
                } else {
                    if (test_s[now] + test_s[next] != g[now][i].cost) {
                        cout << 0 << endl;
                    }
                }
            }
        }
        // even_minを無理やり1に合わせる
        odd_min -= 1 - even_min;
        even_min = 1;
        if (odd_min < 1) {
            cout << 0 << endl;
        } else {
            cout << odd_min << endl;
        }
        return 0;
    } else {  //二部グラフでないとき
        int a = 0, b = 0;
        int now = cycle_even;
        // a
        while (now != 0) {
            int temp = e[now][from[now]];
            if (bipartite[now] == 0) {
                a -= temp;
            } else {
                a += temp;
            }
            now = from[now];
        }
        // b
        now = cycle_odd;
        if (bipartite[now] == 0) {
            b -= e[cycle_odd][cycle_even];
        } else {
            b += e[cycle_odd][cycle_even];
        }
        while (now != 0) {
            int temp = e[now][from[now]];
            if (bipartite[now] == 0) {
                b -= temp;
            } else {
                b += temp;
            }
            now = from[now];
        }
    }
}
