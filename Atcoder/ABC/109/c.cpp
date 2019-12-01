#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coord(n);
    for (int i = 0; i < n; i++) {
        cin >> coord[i];
        coord[i] -= x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = gcd(ans, coord[i]);
    }
    cout << ans << endl;
}
