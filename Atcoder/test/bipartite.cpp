#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//連結二部グラフの分割を+1,-1で与える
// graphは隣接リスト
//二部グラフでなかったらbipartite[0]=0
vector<int> bipartite(vector<vector<int>> &graph) {
    vector<int> res(graph.size(), 0);
    res[0] = 1;
    queue<int> bfs;
    bfs.push(0);
    while (bfs.size() > 0) {
        int depart = bfs.front();
        vector<int> dests = graph[depart];
        for (int i = 0; i < (int)dests.size(); i++) {
            if (res[dests[i]] == 0) {
                res[dests[i]] = -res[depart];
                bfs.push(dests[i]);
            } else if (res[dests[i]] * res[depart] == 1) {
                res[0] = 0;
                return res;
            }
        }
        bfs.pop();
    }
    return res;
}

//連結二部グラフか判定
// graphは隣接リスト
bool isBipartite(vector<vector<int>> &graph) {
    vector<int> res(graph.size(), 0);
    res[0] = 1;
    queue<int> bfs;
    bfs.push(0);
    while (bfs.size() > 0) {
        int depart = bfs.front();
        vector<int> dests = graph[depart];
        for (int i = 0; i < (int)dests.size(); i++) {
            if (res[dests[i]] == 0) {
                res[dests[i]] = -res[depart];
                bfs.push(dests[i]);
            } else if (res[dests[i]] * res[depart] == 1) {
                return false;
            }
        }
        bfs.pop();
    }
    return true;
}

int main() {
    vector<vector<int>> g = {{1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}};
    // vector<vector<int>> g = {{1, 3}, {0, 2}, {1, 3}, {2, 0}};
    cout << bipartite(g)[0] << endl;
}
