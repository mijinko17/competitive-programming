#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> data(n);
    for (int i = 0; i < m; i++) {
        int p, y;
        cin >> p >> y;
        p--;
        data[p].push_back(make_pair(y, i));
    }
    for (int i = 0; i < n; i++) {
        sort(all(data[i]));
    }
    vector<pair<int, int>> id(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < data[i].size(); j++) {
            auto now = data[i][j];
            id[now.second] = make_pair(i + 1, j + 1);
        }
    }
    for (int i = 0; i < m; i++) {
        cout << setfill('0') << setw(6) << id[i].first << setw(6)
             << id[i].second << endl;
    }
}
