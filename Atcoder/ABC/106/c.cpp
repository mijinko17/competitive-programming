#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    if (s == string('1', s.length())) {
        cout << 1 << endl;
    } else {
        //初めて1以外が現れるとこの添字
        int n;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '1') {
                n = i;
                break;
            }
        }
        if (n >= k) {
            cout << 1 << endl;
        } else {
            cout << s[n] << endl;
        }
    }
}
