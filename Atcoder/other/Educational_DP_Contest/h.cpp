#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    vector<vector<lint>> dp(h + 1, vector<lint>(w + 1));
}
