#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    lint a, b;
    cin >> a >> b;
    cout << (a * b) / gcd(a, b) << endl;
}
