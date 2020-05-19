#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int c;
        cin >> c;
        vector<int> b(c);
        for (int i = 0; i < c; i++) {
            cin >> b[i];
        }
        if (b.front() == 0 || b.back() == 0) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> dest(c);
        int now = 0;
        int row = 1;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < b[i]; j++) {
                dest[now] = i;
                row = max(row, abs(i - now) + 1);
                now++;
            }
        }
        vector<string> ans(row, string(c, '.'));
        for (int i = 0; i < c; i++) {
            if (dest[i] == i) {
                continue;
            } else if (dest[i] < i) {
                int num = i - dest[i];
                for (int j = 0; j < num; j++) {
                    ans[j][i - j] = '/';
                }
            } else {
                int num = dest[i] - i;
                for (int j = 0; j < num; j++) {
                    ans[j][i + j] = '\\';
                }
            }
        }
        cout << row << endl;
        for (auto e : ans) {
            cout << e << endl;
        }
    }
    return 0;
}
