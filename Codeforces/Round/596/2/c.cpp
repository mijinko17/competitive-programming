#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int bit(int n) {
    int res = 0;
    while (n) {
        res += n % 2;
        n /= 2;
    }
    return res;
}

int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 0; i <= 32; i++) {
        int a = n - i * p;
        if (bit(a) <= i && i <= a) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
