#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// 2進数表記時の桁数
int width(lint x) {
    lint res = 1;
    while (x >> res) res++;
    return res;
}

// 二進数表記した時にxが接頭辞になっていてn以下である自然数の総数
lint prefix(lint x, lint n) {
    if (x <= 0 || x > n) return 0;
    lint res = 0;
    int diff = width(n) - width(x);
    res += (1LL << (diff)) - 1;
    if ((n >> diff) == x) {
        res += n - (x << diff) + 1;
    } else if ((n >> diff) > x) {
        res += (1LL << diff);
    }
    return res;
}

// n以下であって、pathにxを含むような数の総数
lint g(lint x, lint n) {
    int res = prefix(x, n);
    if (x % 2 == 0) res += prefix(x + 1, n);
    return res;
}

int main() {
    lint n, k;
    cin >> n >> k;
    lint ans = 1;
    // y:oddでの最大
    lint ok_odd = 0, no_odd = 1e+18;
    while (abs(ok_odd - no_odd) > 1) {
        lint mid = (ok_odd + no_odd) / 2;
        if (g(2 * mid - 1, n) >= k) {
            ok_odd = mid;
        } else {
            no_odd = mid;
        }
    }
    ans = max(ans, 2 * ok_odd - 1);
    // y:evenでの最大
    lint ok_even = 0, no_even = 1e+18;
    while (abs(ok_even - no_even) > 1) {
        lint mid = (ok_even + no_even) / 2;
        if (g(2 * mid, n) >= k) {
            ok_even = mid;
        } else {
            no_even = mid;
        }
    }
    ans = max(ans, 2 * ok_even);
    cout << ans << endl;
}
