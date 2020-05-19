#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    map<int, bool> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m[t] = true;
    }
    // 縦
    for (int i = 0; i < 3; i++) {
        if (m[a[i][0]] && m[a[i][1]] && m[a[i][2]]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    // 縦
    for (int i = 0; i < 3; i++) {
        if (m[a[0][i]] && m[a[1][i]] && m[a[2][i]]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (m[a[0][0]] && m[a[1][1]] && m[a[2][2]]) {
        cout << "Yes" << endl;
        return 0;
    }
    if (m[a[0][2]] && m[a[1][1]] && m[a[2][0]]) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
