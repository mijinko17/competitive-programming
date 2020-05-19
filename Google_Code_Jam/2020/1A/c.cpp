#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct compass {
    int left;
    int right;
    int up;
    int down;
    compass(int l, int r, int u, int d) : left(l), right(r), up(u), down(d) {}
    compass() {}
};

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int r, c;
        cin >> r >> c;
        vector<vector<int>> floor(r, vector<int>(c));
        vector<vector<compass>> comp(r, vector<compass>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> floor[i][j];
                comp[i][j] = compass(j - 1, j + 1, i - 1, i + 1);
            }
        }
        lint ans = 0;
        vector<vector<bool>> isdead(r, vector<bool>(c, false));
        while (1) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (!isdead[i][j]) {
                        ans += floor[i][j];
                    }
                    // left
                    while (comp[i][j].left >= 0) {
                        if (isdead[i][comp[i][j].left]) {
                            comp[i][j].left--;
                        } else {
                            break;
                        }
                    }
                    // right
                    while (comp[i][j].right < c) {
                        if (isdead[i][comp[i][j].right]) {
                            comp[i][j].right++;
                        } else {
                            break;
                        }
                    }
                    // up
                    while (comp[i][j].up >= 0) {
                        if (isdead[comp[i][j].up][j]) {
                            comp[i][j].up--;
                        } else {
                            break;
                        }
                    }
                    // down
                    while (comp[i][j].down < r) {
                        if (isdead[comp[i][j].down][j]) {
                            comp[i][j].down++;
                        } else {
                            break;
                        }
                    }
                }
            }
            int elim = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (isdead[i][j]) {
                        continue;
                    }
                    int alive = 0;
                    int sum = 0;
                    if (comp[i][j].left >= 0) {
                        alive++;
                        sum += floor[i][comp[i][j].left];
                    }
                    if (comp[i][j].right < c) {
                        alive++;
                        sum += floor[i][comp[i][j].right];
                    }
                    if (comp[i][j].up >= 0) {
                        alive++;
                        sum += floor[comp[i][j].up][j];
                    }
                    if (comp[i][j].down < r) {
                        alive++;
                        sum += floor[comp[i][j].down][j];
                    }
                    if (floor[i][j] * alive < sum) {
                        isdead[i][j] = true;
                        elim++;
                    }
                }
            }
            if (elim == 0) {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
