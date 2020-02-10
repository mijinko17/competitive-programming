#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == 9 && b == 1) {
        cout << 9 << " " << 10 << endl;
    } else if (a == b) {
        cout << a * 10 << " " << b * 10 + 1 << endl;
    } else if (a + 1 == b) {
        cout << b * 10 - 1 << " " << b * 10 << endl;
    } else {
        cout << -1 << endl;
    }
}
