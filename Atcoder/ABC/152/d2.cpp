#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<lint>> count(10, vector<lint>(10, 0));
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        int a = s[0] - '0', b = s.back() - '0';
        count[a][b]++;
    }
    lint ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j < 10; j++) {
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << endl;
}
