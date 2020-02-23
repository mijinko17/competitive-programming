#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//ほげ
//ほげ
// aaa
int main() {
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            for (int k = 0; k <= 5; k++) {
                for (int l = 0; l <= 5; l++) {
                    for (int m = 0; m <= 5; m++) {
                        int num = 0;
                        if (i == 0) {
                            num++;
                        }
                        if (j == 0) {
                            num++;
                        }
                        if (k == 0) {
                            num++;
                        }
                        if (l == 0) {
                            num++;
                        }
                        if (m == 0) {
                            num++;
                        }
                        if (i + j + k + l + m == 5 && num == 2 && i == 0 && j == 0) {
                            cout << i << " " << j << " " << k << " " << l << " " << m << endl;
                        }
                    }
                }
            }
        }
    }
}
