#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, sx, sy;
    cin >> n >> sx >> sy;
    int north, east, south, west;
    north = east = south = west = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > sy) {
            north++;
        }
        if (y < sy) {
            south++;
        }
        if (x < sx) {
            west++;
        }
        if (x > sx) {
            east++;
        }
    }
    int m = max({north, east, south, west});
    cout << m << endl;
    if (north == m) {
        cout << sx << " " << sy + 1 << endl;
        return 0;
    }
    if (south == m) {
        cout << sx << " " << sy - 1 << endl;
        return 0;
    }
    if (east == m) {
        cout << sx + 1 << " " << sy << endl;
        return 0;
    }
    if (west == m) {
        cout << sx - 1 << " " << sy << endl;
        return 0;
    }
}
