#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string all_a = string(300, 'a'), all_b = string(300, 'b');
    int x, y;
    cout << all_a << endl;
    cin >> x;
    x = 300 - x;
    cout << all_b << endl;
    cin >> y;
    y = 300 - y;
    string f = string(x, 'a');
    int react;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j <= f.length(); j++) {
            string front = f.substr(0, j), back = f.substr(j);
            string cand = front + 'b' + back;
            cout << cand << endl;
            cin >> react;
            if (react <= x + y - (int)cand.length()) {
                f = cand;
                break;
            }
        }
    }
}
