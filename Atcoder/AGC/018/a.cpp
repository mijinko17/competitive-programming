#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        g = gcd(g, a);
    }
    if (k % g == 0) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
