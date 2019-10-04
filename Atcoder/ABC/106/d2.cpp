#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    // train[i][j]:i~j間の電車の数
    vector<vector<int>> train(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        train[l - 1][r - 1]++;
    }
    // s[i][j]:[0,i)×[0,j)の和
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + train[i][j];
        }
    }
    //クエリに答える
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << s[y][y] - s[y][x - 1] - s[x - 1][y] + s[x - 1][x - 1] << endl;
    }
    return 0;
}
