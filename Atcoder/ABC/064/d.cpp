#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int left = 0, right = 0;
    int prefix = 0, suffix = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left < right) {
            prefix++;
            left++;
        }
    }
    suffix = left - right;
    cout << string(prefix, '(') + s + string(suffix, ')');
}
