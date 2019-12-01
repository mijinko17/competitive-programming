#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 != 0) {
        cout << "No" << endl;
        return 0;
    } else {
        int m = n / 2;
        for (int i = 0; i < m; i++) {
            if (s[i] != s[i + m]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
