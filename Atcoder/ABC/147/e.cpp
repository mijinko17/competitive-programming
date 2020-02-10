#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }
    vector<vector<vector<bool>>> representable(
        h + 1,
        vector<vector<bool>>(w, vector<bool>(h * w * 80 * 2 + 4, false)));
    int mid = h * w * 80 + 2;
    representable[0][0][mid + a[0][0] - b[0][0]] = true;
    representable[0][0][mid - a[0][0] + b[0][0]] = true;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < h * w * 80 * 2 + 4; k++) {
                if (representable[i][j][k]) {
                    if (j + 1 < w) {
                        int temp = k + a[i][j + 1] - b[i][j + 1];
                        if (temp >= 0 && temp < mid * 2) {
                            representable[i][j + 1]
                                         [k + a[i][j + 1] - b[i][j + 1]] = true;
                        }
                        int temp2 = k - a[i][j + 1] + b[i][j + 1];
                        if (temp2 >= 0 && temp2 < mid * 2) {
                            representable[i][j + 1]
                                         [k - a[i][j + 1] + b[i][j + 1]] = true;
                        }
                    }
                    int temp = k + a[i + 1][j] - b[i + 1][j];
                    if (temp >= 0 && temp < mid * 2) {
                        representable[i + 1][j][k + a[i + 1][j] - b[i + 1][j]] =
                            true;
                    }

                    int temp2 = k - a[i + 1][j] + b[i + 1][j];
                    if (temp2 >= 0 && temp2 < mid * 2) {
                        representable[i + 1][j][k - a[i + 1][j] + b[i + 1][j]] =
                            true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < mid; i++) {
        if (representable[h - 1][w - 1][i + mid] ||
            representable[h - 1][w - 1][mid - 1]) {
            cout << i << endl;
            return 0;
        }
    }
}
