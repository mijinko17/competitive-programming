#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> trap(n + 1), disarm(n + 1);
    vector<int> d(k, 0);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r >> d[i];
        trap[l].push_back(i);
        disarm[r].push_back(i);
    }
    int ok = 2 * 1e5 + 1, no = -1;
    // x:xより大きいトラップを全部取り除ける の最小値
    bool soldier_isStop = false;
    int soldier_position;
    while (abs(ok - no) > 1) {
        int mid = (ok + no) / 2;
        unordered_set<int> task;
        int time_required = n + 1;
        for (int i = 1; i <= n; i++) {
            // add traps
            for (int j = 0; j < trap[i].size(); j++) {
                if (d[trap[i][j]] > mid) {
                    task.insert(trap[i][j]);
                }
            }
            //トラップが残ってるなら止まる
            if (!task.empty() && !soldier_isStop) {
                soldier_isStop = true;
                soldier_position = i - 1;
            }
            // disarm traps
            for (int j = 0; j < disarm[i].size(); j++) {
                task.erase(disarm[i][j]);
            }
            //トラップがないならソルジャーのストップを解除
            if (task.empty() && soldier_isStop) {
                time_required += 2 * (i - soldier_position);
                soldier_isStop = false;
            }
        }
        if (time_required <= t) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << a.end() - lower_bound(a.begin(), a.end(), ok) << endl;
}
