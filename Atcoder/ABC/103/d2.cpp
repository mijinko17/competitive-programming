#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
vector<pair<int, int>> ab;

int main() {
    cin >> n >> m;
    ab.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> ab[i].first >> ab[i].second;
    }
    auto compare = [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; };
    sort(ab.begin(), ab.end(), compare);
    // r~r+1を切った
    int r = -1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (r < ab[i].first) {
            r = ab[i].second - 1;
            ans++;
        }
    }
    cout << ans << endl;
}
