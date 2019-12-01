#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> hw(n);
    for (int i = 0; i < n; i++) {
        cin >> hw[i].first >> hw[i].second;
    }
    sort(all(hw), [](const pair<int, int> x, const pair<int, int> y) {
        return x.first == y.first ? x.second > y.second : x.first < y.first;
    });
}
