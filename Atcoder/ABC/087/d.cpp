#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

struct edge {
    //(fromの位置)+dist=(personの位置)
    int person;
    int dist;
    edge(int p, int d) : person(p), dist(d){};
};

void yes() {
    cout << "Yes" << endl;
}
void no() {
    cout << "No" << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;
        graph[l].push_back(edge(r, d));
        graph[r].push_back(edge(l, -d));
    }
    //一回でもwhileで登場したらtrue
    vector<bool> check(n, false);
    //人の"位置"
    // x[i]==-1e+9-1の時は位置未定義
    vector<int> x(n, -1e+9 - 1);
    for (int i = 0; i < n; i++) {
        if (check[i] == true) continue;
        x[i] = 0;
        queue<int> bfs;
        bfs.push(i);
        while (bfs.size() > 0) {
            int now = bfs.front();
            for (int j = 0; j < graph[now].size(); j++) {
                int dest = graph[now][j].person;
                if (x[dest] < -1e+9) {
                    x[dest] = x[now] + graph[now][j].dist;
                    bfs.push(dest);
                } else {
                    if (x[dest] != x[now] + graph[now][j].dist) {
                        no();
                        return 0;
                    }
                }
            }
            check[now] = true;
            bfs.pop();
        }
    }
    yes();
}
