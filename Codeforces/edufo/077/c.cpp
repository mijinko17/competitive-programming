#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        lint r, b, k;
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        lint g = gcd(r, b);
        r /= g, b /= g;
        if (b - 2 >= r * (k - 1)) {
            cout << "REBEL" << endl;
        } else {
            cout << "OBEY" << endl;
        }
        vector<int> v;
    }
}
