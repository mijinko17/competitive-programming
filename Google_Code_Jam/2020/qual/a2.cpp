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
        vector<set<int>> row(n), column(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m;
                cin >> m;
                row[i].insert(m);
                column[j].insert(m);
                if (i == j) trace += m;
            }
        }
        int row_rep = 0, column_rep = 0;
        for (int i = 0; i < n; i++) {
            if (row[i].size() < n) {
                row_rep++;
            }
            if (column[i].size() < n) {
                column_rep++;
            }
        }
        cout << trace << " " << row_rep << " " << column_rep << endl;
    }
    return 0;
}
