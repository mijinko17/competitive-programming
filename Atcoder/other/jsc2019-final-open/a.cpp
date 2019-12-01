#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

using Complex = complex<double>;
vector<Complex> dft(vector<Complex> A, int N, int sgn = 1) {
    if (N == 1) return A;

    vector<Complex> F(N / 2), G(N / 2);
    for (int i = 0; i < N / 2; i++) {
        F[i] = A[2 * i + 0];
        G[i] = A[2 * i + 1];
    }

    F = dft(F, N / 2, sgn);
    G = dft(G, N / 2, sgn);

    Complex zeta(cos(2.0 * M_PI / N), sin(2.0 * M_PI / N) * sgn);
    Complex pow_zeta = 1;

    for (int i = 0; i < N; i++) {
        A[i] = F[i % (N / 2)] + pow_zeta * G[i % (N / 2)];
        pow_zeta *= zeta;
    }
    return A;
}

vector<Complex> inv_dft(vector<Complex> A, int N) {
    A = dft(A, N, -1);
    for (int i = 0; i < N; i++) {
        A[i] /= N;
    }
    return A;
}

vector<Complex> multiply(vector<Complex> A, vector<Complex> B) {
    int sz = A.size() + B.size() + 1;
    int N = 1;
    while (N < sz) N *= 2;

    A.resize(N), B.resize(N);
    A = dft(A, N);
    B = dft(B, N);

    vector<Complex> F(N);
    for (int i = 0; i < N; i++) {
        F[i] = A[i] * B[i];
    }
    return inv_dft(F, N);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Complex> A(100000, Complex(0)), B(100000, Complex(0));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A[a] = Complex(1);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        B[b] = Complex(1);
    }
    vector<Complex> ans = multiply(A, B);
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << endl;
    }
}
