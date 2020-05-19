#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint h, w;

int main() {
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (h * w % 2 == 0) {
        cout << h * w / 2 << endl;
    } else {
        cout << (h * w + 1) / 2 << endl;
    }
}
