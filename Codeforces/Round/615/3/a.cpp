#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> abc(3);
        for (int i = 0; i < 3; i++) {
            cin >> abc[i];
        }
        int n;
        cin >> n;
        sort(abc.begin(), abc.end());
        for (int i = 0; i < 2; i++) {
            n -= abc[2] - abc[i];
        }
        if (n < 0 || n % 3 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
