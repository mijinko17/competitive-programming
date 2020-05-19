#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int a, b;

int main() {
    cin >> a >> b;
    vector<string> s(100, string(50, '.') + string(50, '#'));
    a--, b--;
    for (int i = 0; i < 100 && b; i += 2) {
        for (int j = 0; j < 49 && b; j += 2) {
            s[i][j] = '#';
            b--;
        }
    }
    for (int i = 0; i < 100 && a; i += 2) {
        for (int j = 99; j > 50 && a; j -= 2) {
            s[i][j] = '.';
            a--;
        }
    }
    cout << 100 << ' ' << 100 << endl;
    for (auto e : s) {
        cout << e << endl;
    }
}
