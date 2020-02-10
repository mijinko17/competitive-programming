#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<pair<lint, lint>> lr;

int main() {
    cin >> n;
    lr.resize(n);
    for (int i = 0; i < n; i++) {
        int x, tl;
        cin >> x >> tl;
        lr[i].first = x - tl;
        lr[i].second = x + tl;
    }
    sort(lr.begin(), lr.end(),
         [](const pair<lint, lint> a, const pair<lint, lint> b) {
             return a.first == b.first ? a.second < b.second
                                       : a.first > b.first;
         });
    auto now = lr.front();
    lint ans = 0;
    for (int i = 1; i < n; i++) {
        if (lr[i].second > now.first) {
            ans++;
        } else {
            now = lr[i];
        }
    }
    cout << n - ans << endl;
}
