#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = to_string(n);
    int k = s.back() - '0';
    if (k == 0 || k == 1 || k == 6 || k == 8) {
        cout << "pon" << endl;
    } else if (k == 3) {
        cout << "bon" << endl;
    } else {
        cout << "hon" << endl;
    }
}
