#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    char temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp == '1') {
                graph[i].push_back(j);
            }
        }
    }
    //二部グラフか判定
    vector<int> index(n, -1);
    queue<int> q_bip;
    q_bip.push(0);
    index[0] = 0;
    while (q_bip.size() > 0) {
        int target = q_bip.front();
        for (int i = 0; i < graph[target].size(); i++) {
            if (index[graph[target][i]] == -1) {
                index[graph[target][i]] = 1 - index[target];
                q_bip.push(graph[target][i]);
            } else if (index[graph[target][i]] == index[target]) {
                cout << -1 << endl;
                return 0;
            }
        }
        q_bip.pop();
    }
    int ans = 0;
    //各頂点ごとにもっとも遠い地点までの距離を求める
    for (int i = 0; i < n; i++) {
        int dist;
        queue<pair<int, int>> q_dist;
        q_dist.push(make_pair(i, 0));
        vector<int> arrived(n, 0);
        arrived[i] = 1;
        while (q_dist.size() > 0) {
            pair<int, int> target = q_dist.front();
            dist = target.second;
            for (int j = 0; j < graph[target.first].size(); j++) {
                int dest = graph[target.first][j];
                if (arrived[dest] == 0) {
                    arrived[dest] = 1;
                    q_dist.push(make_pair(dest, target.second + 1));
                }
            }
            q_dist.pop();
        }
        ans = max(ans, dist);
    }
    cout << ans + 1 << endl;
}
