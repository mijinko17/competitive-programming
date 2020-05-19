#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        cout << "Case #" << z + 1 << ": ";
        int n;
        cin >> n;
        int trace = 0;
        vector<bitset<100>> row(n, 0), column(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m;
                cin >> m;
                if (i == j) trace += m;
                m--;
                row[i][m] = 1;
                column[j][m] = 1;
            }
        }
        int row_dup = 0, column_dup = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] != (1 << n) - 1) {
                row_dup++;
            }
            if (column[i] != (1 << n) - 1) {
                column_dup++;
            }
        }
        cout << trace << ' ' << row_dup << ' ' << column_dup << endl;
    }
    return 0;
}
