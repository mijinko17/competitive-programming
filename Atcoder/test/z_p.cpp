#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

// Z_p
// cin以外の大体のことはできる
template <int p>
struct int_p {
    long long int val;
    template <typename T>
    int_p(T x) {
        val = x % p;
    }
    // [0,p)の範囲の代表元
    long long int repr() const {
        if (val < 0) return val + p;
        return val;
    }
    //環演算
    int_p<p> operator+(int_p<p>& a) const {
        return int_p<p>(val + a.repr());
    }
    int_p<p> operator+(int& a) const {
        return int_p<p>(val + a);
    }
    int_p<p> operator-(int_p<p>& a) const {
        return int_p<p>(val - a.repr());
    }
    int_p<p> operator-(int& a) const {
        return int_p<p>(val - a);
    }
    int_p<p> operator*(int_p<p>& a) const {
        return int_p<p>(val * a.repr());
    }
    int_p<p> operator*(int& a) const {
        return int_p<p>(val * a);
    }
    //代入
    template <typename T>
    int_p<p>& operator=(T x) {
        val = x;
        return *this;
    }
    int_p<p>& operator+=(const int_p<p> a) {
        val = (val + a.repr()) % p;
        return *this;
    }
    int_p<p>& operator+=(const int a) {
        val = (val + a) % p;
        return *this;
    }
    int_p<p>& operator-=(const int_p<p> a) {
        val = (val - a.repr()) % p;
        return *this;
    }
    int_p<p>& operator-=(const int a) {
        val = (val - a) % p;
        return *this;
    }
    int_p<p>& operator*=(const int_p<p> a) {
        val = (val * a.repr()) % p;
        return *this;
    }
    int_p<p>& operator*=(const int a) {
        val = (val * a) % p;
        return *this;
    }
};
// coutとかできるようにする
template <int p>
ostream& operator<<(ostream& os, const int_p<p>& x) {
    os << x.repr();
    return os;
};

int main() {
    int n;
    cin >> n;
    const long long int MOD = 1e+9 + 7;
    int_p<MOD> ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    cout << ans << endl;
}
