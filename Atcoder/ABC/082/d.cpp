#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    s = s + 'T';
    x = abs(x), y = abs(y);
    int n = s.length();
    bool isHori = true;
    vector<int> horizontal, vertical;
    int len = 0;
    int vert_sum = 0, hori_sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            if (isHori) {
                horizontal.push_back(len * 2);
                hori_sum += len;
            } else {
                vertical.push_back(len * 2);
                vert_sum += len;
            }
            len = 0;
            isHori = !isHori;
        } else {
            len++;
        }
    }
    //水平or垂直方向にそこにいけるか
    vector<vector<bool>> vdp(vertical.size() + 1,
                             vector<bool>(2 * n + 1, false));
    vector<vector<bool>> hdp(horizontal.size() + 1,
                             vector<bool>(2 * n + 1, false));
    // v
    vdp[0][0] = true;
    for (int i = 0; i < vertical.size(); i++) {
        for (int j = 0; j <= 2 * (n + 1); j++) {
            vdp[i + 1][j] = vdp[i + 1][j] || vdp[i][j];
            if (j + vertical[i] < 2 * (n + 1)) {
                vdp[i + 1][j + vertical[i]] =
                    vdp[i][j] || vdp[i][j + vertical[i]];
            }
        }
    }
    // h
    hdp[0][0] = true;
    for (int i = 0; i < horizontal.size(); i++) {
        for (int j = 0; j <= 2 * n; j++) {
            hdp[i + 1][j] = hdp[i + 1][j] || hdp[i][j];
            if (j + horizontal[i] < 2 * (n + 1)) {
                hdp[i + 1][j + horizontal[i]] =
                    hdp[i][j] || hdp[i][j + horizontal[i]];
            }
        }
    }
    if (hdp[horizontal.size()][x + hori_sum] &&
        vdp[vertical.size()][y + vert_sum]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
