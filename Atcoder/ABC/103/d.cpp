#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    // a\in cut[b]:a~b間を切る必要がある
    vector<vector<int>> cut(n);
    // left[i]==true:i~どっかを切る必要がある
    vector<bool> left(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cut[b].push_back(a);
        left[a] = true;
    }
    for (int i = 0; i < n; i++) {
        sort(all(cut[i]));
    }
    int last_cut = -1;
    bool has_task = false;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (left[i]) {
            has_task = true;
        }
        if (has_task) {
            auto itr = upp
        }
    }
}
