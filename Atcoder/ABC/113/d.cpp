#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

// a^n mod pを計算　O(log n)
long long int pow_p(long long int a, long long int n, long long int p) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = pow_p(a, n / 2, p);
        if (n % 2 == 0) {
            return (temp * temp) % p;
        } else {
            return (((temp * temp) % p) * a) % p;
        }
    }
}

// Z_pでのaの逆元を計算 O(log p)
long long int inv_p(long long int a, long long int p) {
    return pow_p(a, p - 2, p);
}

int main() {
    lint mod = 1e+9 + 7;
    //行:1-indexed、列:0-index
    int h, w, k;
    cin >> h >> w >> k;
    lint p_str_ = pow_p(2, max(w - 2, 0), mod);
    lint p_straight = pow_p(2, max(w - 2, 0), mod);
    // s[i][j]:i行目の段階でj列にくる阿弥陀の数
    vector<vector<lint>> s(h + 1, vector<lint>(w, 0));
    s[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            cout << i << " " << j << endl;
            lint temp;
            if (j == 0) {
                temp = s[i - 1][j] * p * 4 + s[i - 1][j + 1] * p * 2;
            } else if (j == w - 1) {
                temp = s[i - 1][j] * p * 4 + s[i - 1][j - 1] * p * 2;
            } else {
                temp =
                    s[i - 1][j] * p * 2 + s[i - 1][j - 1] * p + s[i - 1][j] * p;
            }
            temp %= mod;
            s[i][j] += temp;
            s[i][j] %= mod;
        }
    }
    cout << s[h][k] << endl;
}
