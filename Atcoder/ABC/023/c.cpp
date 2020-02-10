#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int r, c, k, n;
vector<pair<int, int>> candy;

int main() {
    cin >> r >> c >> k >> n;
    candy.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        candy[i] = {a, b};
    }
    vector<lint> num_r(r, 0), num_c(c, 0);
    for (int i = 0; i < n; i++) {
        num_r[candy[i].first]++;
        num_c[candy[i].second]++;
    }
    unordered_map<int, lint> count;
    for (int i = 0; i < c; i++) {
        count[num_c[i]]++;
    }
    lint ans = 0;
    for (int i = 0; i < r; i++) {
        ans += count[k - num_r[i]];
    }
    for (int i = 0; i < n; i++) {
        int score = num_r[candy[i].first] + num_c[candy[i].second];
        if (score == k) {
            ans--;
        } else if (score == k + 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
