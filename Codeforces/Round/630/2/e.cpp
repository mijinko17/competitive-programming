#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint mod = 998244353;
lint n, m, l, r;

// a^n mod pを計算　O(log n)
long long pow_mod(long long a, long long n, long long p) {
    if (n == 0) return 1;
    if (n & 1) return pow_mod(a, n - 1, p) * a % p;
    long long temp = pow_mod(a, n / 2, p);
    return temp * temp % p;
}

template <typename T>
struct matrix {
    int size;
    vector<vector<T>> data;
    matrix(int _size) : size(_size) {
        data.assign(size, vector<T>(size, (T)0));
    }
    vector<T>& operator[](int k) {
        return data[k];
    }
    matrix<T> operator*(matrix<T> mat) {
        matrix<T> res(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    res[i][j] = (res[i][j] + data[i][k] * mat.data[k][j] % mod) % mod;
                }
            }
        }
        return res;
    }
    matrix<T> pow(lint k) {
        if (k == 0) {
            auto e = matrix<T>(size);
            for (int i = 0; i < size; i++) e[i][i] = 1;
            return e;
        };
        if (k % 2 == 1) return *this * pow(k - 1);
        auto half = pow(k / 2);
        return half * half;
    }
};

int main() {
    cin >> n >> m >> l >> r;
    if (n * m % 2 == 1) {
        cout << pow_mod(r - l + 1, n * m, mod) << endl;
    } else {
        lint x = r / 2 - (l - 1) / 2;
        lint y = r - l + 1 - x;
        matrix<lint> mat(2);
        mat[0][0] = mat[1][1] = x;
        mat[1][0] = mat[0][1] = y;
        cout << mat.pow(n * m)[0][0] << endl;
    }
}
