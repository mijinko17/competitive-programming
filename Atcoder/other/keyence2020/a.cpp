#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int h, w, n;

int main() {
    cin >> h >> w >> n;
    if (h < w) {
        swap(h, w);
    }
    cout << (n + h - 1) / h << endl;
}
