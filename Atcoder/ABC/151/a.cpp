#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    char c;
    cin >> c;
    char ans = (c - 'a' + 1) % 26 + 'a';
    cout << ans << endl;
}
