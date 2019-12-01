#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    // d[i]:i円を作るのに必要な最小枚数
    vector<int> d(n + 1, -1);
    d[0] = 0;
    queue<int> bfs;
    bfs.push(0);
    while (d[n] == -1) {
        int now = bfs.front();
        bfs.pop();
        for (int i = 0; i < m; i++) {
            if (now + c[i] <= n && d[now + c[i]] == -1) {
                d[now + c[i]] = d[now] + 1;
                bfs.push(now + c[i]);
            }
        }
    }
    cout << d[n] << endl;
}
