#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sum = 0;
        int zeros = 0;
        int evens = 0;
        for (int j = 0; j < s.length(); j++) {
            sum += s[j] - '0';
            if (s[j] == '0') zeros++;
            if ((s[j] - '0') % 2 == 0) evens++;
        }
        if (sum % 3 == 0 && zeros > 0 && evens >= 2) {
            cout << "red" << endl;
        } else {
            cout << "cyan" << endl;
        }
    }
}
