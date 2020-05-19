#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    vector<vector<int>> c(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        int diff = c[i + 1][0] - c[i][0];
        for (int j = 1; j <= 2; j++) {
            if (c[i + 1][j] - c[i][j] != diff) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
