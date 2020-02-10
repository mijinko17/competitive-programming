#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> rgb(3);
        for (int i = 0; i < 3; i++) {
            cin >> rgb[i];
        }
        sort(rgb.begin(), rgb.end());
        if (rgb[2] - rgb[1] <= rgb[0] + 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
