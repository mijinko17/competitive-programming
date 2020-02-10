#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, c;
vector<vector<pair<int, int>>> stc;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n >> c;
    stc.resize(c);
    for (int i = 0; i < n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        stc[c].push_back({s, t});
    }
    vector<pair<int, int>> task;
    for (int i = 0; i < c; i++) {
        if (stc[i].empty()) continue;
        sort(stc[i].begin(), stc[i].end());
        task.push_back(stc[i][0]);
        for (int j = 1; j < stc[i].size(); j++) {
            if (stc[i][j].first == stc[i][j - 1].second) {
                task.back().second = stc[i][j].second;
            } else {
                task.push_back((stc[i][j]));
            }
        }
    }
    vector<int> event(1e+5 + 2, 0);
    for (auto e : task) {
        event[e.first]++;
        event[e.second + 1]--;
    }
    int ans = 0;
    int need = 0;
    for (int i = 0; i < event.size(); i++) {
        need += event[i];
        chmax(ans, need);
    }
    cout << ans << endl;
}
