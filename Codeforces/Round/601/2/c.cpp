#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(n, 0);
    map<pair<int, int>, vector<int>> mp;
    for (int i = 0; i < n - 2; i++) {
        vector<int> t(3);
        for (int j = 0; j < 3; j++) {
            cin >> t[j];
            t[j]--;
            count[t[j]]++;
        }
        sort(t.begin(), t.end());
        mp[make_pair(t[0], t[1])].push_back(t[2]);
        mp[make_pair(t[1], t[2])].push_back(t[0]);
        mp[make_pair(t[0], t[2])].push_back(t[1]);
    }
    int a = -1, b = -1, c;
    for (int i = 0; i < n; i++) {
        if (count[i] == 1) a = i;
        if (count[i] == 2) b = i;
        if (a >= 0 && b >= 0 && mp[{min(a, b), max(a, b)}].size() > 0) {
            c = mp[{min(a, b), max(a, b)}][0];
            break;
        }
    }
    vector<int> ans = {a, b, c};
    for (int i = 3; i < n; i++) {
        auto now =
            make_pair(min(ans[i - 2], ans[i - 1]), max(ans[i - 2], ans[i - 1]));
        int next = mp[now][0] == ans[i - 3] ? mp[now][1] : mp[now][0];
        ans.push_back(next);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
}
