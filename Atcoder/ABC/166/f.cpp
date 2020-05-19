#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (a + b + c == 1) {
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == "AB") {
                if (c == 1) {
                    cout << "No" << endl;
                } else {
                }
            }
        }
    }
}
