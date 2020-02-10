#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<bitset<100>> ff(n, bitset<100>(0));
    for (int z = 0; z < q; z++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            ff[a][b] = 1;
        } else if (type == 2) {
            int a;
            cin >> a;
            a--;
            for (int i = 0; i < n; i++) {
                if (ff[i][a]) {
                    ff[a][i] = 1;
                }
            }
        } else {
            int a;
            cin >> a;
            a--;
            bitset<100> temp = 0;
            for (int i = 0; i < n; i++) {
                if (ff[a][i]) {
                    temp |= ff[i];
                }
            }
            ff[a] |= temp;
            ff[a][a] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ff[i][j]) {
                cout << "Y";
            } else {
                cout << "N";
            }
        }
        cout << endl;
    }
}
