#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

using Complex = complex<double>;

// 離散高速フーリエ変換 数列の長さは2冪を仮定
vector<Complex> DFT(vector<Complex>& f, int sign = 1) {
    int n = f.size();
    if (n == 1) return f;
    vector<Complex> f0(n / 2), f1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        f0[i] = f[2 * i + 0];
        f1[i] = f[2 * i + 1];
    }
    f0 = DFT(f0, sign), f1 = DFT(f1, sign);
    vector<Complex> res(n);
    Complex zeta(cos(2 * M_PI / n), sin(2 * M_PI / n) * sign);
    Complex pow_zeta(1);
    for (int i = 0; i < n; i++) {
        res[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)];
        pow_zeta *= zeta;
    }
    return res;
}
// DFTの逆変換
vector<Complex> inv_DFT(vector<Complex> f) {
    int n = f.size();
    vector<Complex> res = DFT(f, -1);
    for (int i = 0; i < n; i++) res[i] /= n;
    return res;
}
// 複素の多項式の積
vector<Complex> multiply(vector<Complex> f, vector<Complex> g) {
    int temp = f.size() + g.size() - 1;
    int n = 1;
    while (n < temp) n <<= 1;
    f.resize(n), g.resize(n);
    f = DFT(f), g = DFT(g);
    for (int i = 0; i < n; i++) f[i] *= g[i];
    f = inv_DFT(f);
    f.resize(temp);
    return f;
}

int main() {
    int n;
    cin >> n;
    vector<Complex> a(n + 1), b(n + 1);
    a[0] = b[0] = Complex(0, 0);
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        a[i + 1] = Complex(s, 0);
        b[i + 1] = Complex(t, 0);
    }
    vector<Complex> c = multiply(a, b);
    for (int i = 1; i <= 2 * n; i++) {
        cout << (int)(c[i].real() + 0.5) << endl;
    }
}
