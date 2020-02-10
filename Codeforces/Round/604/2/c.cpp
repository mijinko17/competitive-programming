#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        // 2
        // 金は~[0,gold)まで塗れる
        int gold = 1;
        while (p[gold - 1] == p[gold]) {
            gold++;
        }
        // 銀は~[gold,silver)まで塗れる
        int silver = gold + 1;
        while (silver < n &&
               (gold >= silver - gold || p[silver - 1] == p[silver])) {
            silver++;
        }
        //   // 銅は~[silver,bronze)まで塗れる
        //   int bronze = silver + 1;
        //   while (bronze < n &&
        //          (gold >= bronze - silver || p[bronze - 1] == p[bronze])) {
        //       bronze++;
        //   }
        // 銅は~[silver,bronze)まで塗れる
        int bronze = n / 2;
        while (bronze - 1 >= 0 && p[bronze - 1] == p[bronze]) {
            bronze--;
        }
        if (gold < silver && silver < bronze && gold < silver - gold &&
            gold < bronze - silver && bronze <= n / 2) {
            cout << gold << " " << silver - gold << " " << bronze - silver
                 << endl;
        } else {
            cout << "0 0 0" << endl;
        }
    }
}
