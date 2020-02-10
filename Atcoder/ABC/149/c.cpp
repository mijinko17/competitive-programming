#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int x;

int main() {
    cin >> x;
    while (1) {
        bool flag = true;
        for (int i = 2; i * 2 <= x; i++) {
            if (x % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << x << endl;
            return 0;
        }
        x++;
    }
}
