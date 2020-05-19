#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a, b;
lint mod = 1000000007;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

pair<lint, lint> reg(lint x, lint y) {
    lint div = gcd(x, y);
    x /= div, y /= div;
    if (y < 0) {
        x *= -1, y *= -1;
    }
    if (y == 0 && x < 0) {
        x *= -1;
    }
    return {x, y};
}

pair<lint, lint> auth(pair<lint, lint> p) {
    lint x = -p.second, y = p.first;
    if (y < 0) {
        x *= -1, y *= -1;
    }
    if (y == 0 && x < 0) {
        x *= -1;
    }
    return {x, y};
}

int main() {
    cin >> n;
    map<pair<lint, lint>, lint> count;
    a.resize(n), b.resize(n);
    vector<pair<lint, lint>> vec;
    lint zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] == 0 && b[i] == 0) {
            zeros++;
            continue;
        }
        auto v = reg(a[i], b[i]);
        vec.push_back(v);
        count[v]++;
    }
    set<pair<lint, lint>> trash;
    lint ans = 1;
    for (int i = 0; i < (int)vec.size(); i++) {
        if (trash.count(vec[i])) {
            continue;
        }
        auto o = auth(vec[i]);
        lint mul = (pow_mod(2, count[vec[i]], mod) + pow_mod(2, count[o], mod) - 1) % mod;
        ans = ans * mul % mod;
        trash.insert(vec[i]);
        trash.insert(o);
    }
    if (ans <= 0) {
        return 1;
    }
    lint res = (zeros % mod + ans % mod - 1) % mod;
    if (res < 0) {
        res = (res + mod) % mod;
    }
    cout << res << endl;
}
