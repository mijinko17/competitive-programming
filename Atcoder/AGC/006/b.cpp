#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < 2 * n - 1; i++) {
            cout << (i - n + x + 2 * n - 1) % (2 * n - 1) + 1 << endl;
        }
    }
}
