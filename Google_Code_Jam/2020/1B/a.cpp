#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string solve(lint x, lint y, string s) {
    if (x == 0 && y == 0) {
        return s;
    }
    if (x == 1 && y == 0) {
        return s + 'E';
    }
    if (x == -1 && y == 0) {
        return s + 'W';
    }
    if (x == 0 && y == 1) {
        return s + 'N';
    }
    if (x == 0 && y == -1) {
        return s + 'S';
    }
    if ((x + y) % 2 == 0) {
        return "IMPOSSIBLE";
    }
    if (x % 2 == 0) {
        if ((x / 2 + (y + 1) / 2) % 2 != 0) {
            return solve(x / 2, (y + 1) / 2, s + 'S');
        } else {
            return solve(x / 2, (y - 1) / 2, s + 'N');
        }
    } else {
        if (((x + 1) / 2 + y / 2) % 2 != 0) {
            return solve((x + 1) / 2, y / 2, s + 'W');
        } else {
            return solve((x - 1) / 2, y / 2, s + 'E');
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        lint x, y;
        cin >> x >> y;
        cout << solve(x, y, "") << endl;
    }
    return 0;
}
