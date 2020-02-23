#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

int main() {
    cin >> n;
    map<string, int> count;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        count[s]++;
    }
    vector<pair<int, string>> v;
    for (auto e : count) {
        v.push_back(make_pair(e.second, e.first));
    }
    sort(v.begin(), v.end());
    int m = v.back().first;
    vector<string> ans;
    for (auto itr = v.rbegin(); itr != v.rend(); itr++) {
        if (itr->first == m) {
            ans.push_back(itr->second);
        } else {
            break;
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
