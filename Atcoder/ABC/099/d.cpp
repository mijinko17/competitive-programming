#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

//全部cに塗り替える時の違和感の合計
int dc(vector<int> clist, int c, vector<vector<int>> d) {
    int res = 0;
    for (int i = 0; i < clist.size(); i++) res += clist[i] * d[i][c];
    return res;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> d(c, vector<int>(c));
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }
    vector<vector<int>> count(3, vector<int>(c, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tc;
            cin >> tc;
            tc--;
            count[(i + j) % 3][tc]++;
        }
    }
    int ans = INT_MAX;
    vector<int> v(3);
    for (int i = 0; i < c; i++) {
        v[0] = dc(count[0], i, d);
        for (int j = 0; j < c; j++) {
            if (i == j) continue;
            v[1] = dc(count[1], j, d);
            for (int k = 0; k < c; k++) {
                if (j == k || k == i) continue;
                v[2] = dc(count[2], k, d);
                chmin(ans, v[0] + v[1] + v[2]);
            }
        }
    }
    cout << ans << endl;
}
