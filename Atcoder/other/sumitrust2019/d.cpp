#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> a(10, false), b(100, false);
    vector<bool> ans(1000);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 100; j++) {
            if (b[j]) {
                ans[j * 10 + (s[i] - '0')] = true;
            }
        }
        for (int j = 0; j < 10; j++) {
            if (a[j]) {
                b[j * 10 + (s[i] - '0')] = true;
            }
        }
        a[s[i] - '0'] = true;
    }
    int r = 0;
    for (int i = 0; i < 1000; i++) {
        if (ans[i]) {
            r++;
        }
    }
    cout << r << endl;
}
