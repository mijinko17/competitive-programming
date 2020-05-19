#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

const int len = 30;

// nCr mod p(n<p)をキビキビ計算する
// 構築:O(n), クエリ:O(1)
struct combination_mod {
    using lint = long long int;
    int sz;
    lint mod;
    vector<lint> fac;
    vector<lint> finv;
    combination_mod(int _sz, lint _mod) : sz(_sz), mod(_mod) {
        fac.assign(sz + 1, 1);
        finv.assign(sz + 1, 1);
        vector<lint> inv(sz + 1, 1);
        for (int i = 2; i <= sz; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    lint query(int n, int r) {
        return fac[n] * (finv[r] * finv[n - r] % mod) % mod;
    }
};

int main() {
    combination_mod comb(1000, 1000000007);
    for (int Z = 10000000; Z < 30000000; Z++) {
        cout << "Case #" << Z + 1 << ": " << endl;
        int n = Z;
        if (n < 500) {
            for (int i = 0; i < n; i++) {
                cout << i + 1 << ' ' << 1 << endl;
            }
            continue;
        }
        lint count = 0;
        n -= len;
        bitset<len> b(n);
        int rem = len;
        bool isleft = false;
        int line = 0;
        for (int i = 0; i < len; i++) {
            if (b[i]) {
                for (int j = 0; j <= i; j++) {
                    // cout << i + 1 << ' ' << (isleft ? j + 1 : i + 1 - j) << endl;
                    count += comb.query(i, isleft ? j : i - j);
                    line++;
                    // cout << count << endl;
                }
                isleft = !isleft;
            } else {
                // cout << i + 1 << ' ' << (isleft ? 1 : i + 1) << endl;
                count += comb.query(i, isleft ? 0 : i);
                line++;
                // cout << count << endl;
                rem--;
            }
        }
        for (int i = 0; i < rem; i++) {
            // cout << len + i + 1 << ' ' << (isleft ? 1 : len + i + 1) << endl;
            count += comb.query(len + i, isleft ? 0 : len + i);
            line++;
            // cout << count << endl;
        }
        if (count != n + len) {
            cout << n + len << endl;
            cout << count << endl;
            cout << "!WARNING!" << endl;
            break;
        }
        cout << line << endl;
        if (line > 500) {
            cout << "!WARNING!" << endl;
            break;
        }
    }
    return 0;
}
