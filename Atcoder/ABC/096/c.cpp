#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] != '#') {
                continue;
            }
            bool flag = false;
            if (i - 1 >= 0 && s[i - 1][j] == '#') {
                flag = true;
            }
            if (i + 1 < h && s[i + 1][j] == '#') {
                flag = true;
            }
            if (j - 1 >= 0 && s[i][j - 1] == '#') {
                flag = true;
            }
            if (j + 1 < w && s[i][j + 1] == '#') {
                flag = true;
            }
            if (!flag) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
