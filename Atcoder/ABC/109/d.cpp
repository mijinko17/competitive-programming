#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int h, w;
vector<vector<int>> a;

pair<int, int> next_index(pair<int, int> xy) {
    int x = xy.first, y = xy.second;
    if (x % 2 == 0) {
        if (y == w - 1) {
            return {x + 1, w - 1};
        } else {
            return {x, y + 1};
        }
    } else {
        if (y == 0) {
            return {x + 1, 0};
        } else {
            return {x, y - 1};
        }
    }
}

int main() {
    cin >> h >> w;
    a.assign(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    pair<int, int> now = {0, 0};
    pair<int, int> end = make_pair(h - 1, h % 2 == 0 ? 0 : w - 1);
    while (now != end) {
        auto next = next_index(now);
        if (a[now.first][now.second] % 2 != 0) {
            a[now.first][now.second]--;
            a[next.first][next.second]++;
            ans.push_back({now, next});
        }
        now = next;
    }
    cout << ans.size() << endl;
    for (auto e : ans) {
        cout << e.first.first + 1 << " " << e.first.second + 1 << " " << e.second.first + 1 << " "
             << e.second.second + 1 << endl;
    }
    return 0;
}
