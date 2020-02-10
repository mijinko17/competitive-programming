#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> candy(3);
        for (int i = 0; i < 3; i++) {
            cin >> candy[i];
        }
        sort(candy.begin(), candy.end());
        int ans = 0;
        //まず少ない飴を使い切る
        ans += candy[0];
        if (candy[0] <= candy[2] - candy[1]) {
            candy[2] -= candy[0];
            candy[0] = 0;
        } else {
            candy[0] -= candy[2] - candy[1];
            candy[2] -= candy[0] / 2;
            candy[1] -= (candy[0] + 1) / 2;
            candy[0] = 0;
        }
        ans += candy[1];
        cout << ans << endl;
    }
}
