#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cut(m);
    for (int i = 0; i < m; i++) {
        cin >> cut[i].first >> cut[i].second;
        cut[i].first--, cut[i].second--;
    }
    sort(cut.begin(), cut.end());
    auto itr = cut.begin();
    int ans = 0;
    //今切ってる一番右の橋の添え字
    int cut_right = -1;
    while (itr != cut.end()) {
        cout << itr - cut.begin() << endl;
        ans++;
        cut_right = itr->second - 1;
        itr = upper_bound(cut.begin(), cut.end(), make_pair(cut_right, -1));
        if (ans > 100) {
            break;
        }
    }
    cout << ans << endl;
}
