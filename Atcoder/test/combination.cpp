#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//コンビネーション(パスカルの三角形)
vector<vector<long long int>> comb(long long int n) {
    vector<vector<long long int>> res(n + 1, vector<long long int>(n + 1, 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

int main() {
    vector<vector<long long int>> v = comb(50);
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
