#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;

int rev(int x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoi(s);
}

pair<int, int> operation(pair<int, int> p) {
    if (p.first * p.second == 0) {
        return make_pair(0, 0);
    }
    if (p.first < p.second) {
        p.first = rev(p.first);
    } else {
        p.second = rev(p.second);
    }
    if (p.first < p.second) {
        p.second -= p.first;
    } else {
        p.first -= p.second;
    }
    return p;
}

// 2次元->1次元
int p2i(pair<int, int> p) {
    return p.first * 1000 + p.second;
}

int main() {
    cin >> n >> m;
    // doubling[i][j]:i番目に2^j回操作したやつ
    vector<vector<pair<int, int>>> doubling(1000 * 1000, vector<pair<int, int>>(21));
    // 初期値入れる
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            doubling[p2i({i, j})][0] = operation({i, j});
        }
    }
    // ダブリング
    for (int k = 1; k <= 20; k++) {
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                doubling[p2i({i, j})][k] = doubling[p2i(doubling[p2i({i, j})][k - 1])][k - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (doubling[p2i({i, j})].back() != make_pair(0, 0)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
