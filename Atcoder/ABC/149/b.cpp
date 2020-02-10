#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint a, b, k;

int main() {
    cin >> a >> b >> k;
    if (a >= k) {
        a -= k;
    } else {
        k -= a;
        a = 0;
        if (b >= k) {
            b -= k;
        } else {
            b = 0;
        }
    }
    cout << a << " " << b << endl;
}
