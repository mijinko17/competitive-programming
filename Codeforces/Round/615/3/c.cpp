#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n != 1) res[n]++;
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        lint n;
        cin >> n;
        lint a, b, c;
        auto pf = pf_um(n);
        if (pf.size() == 1) {
            if (pf.begin()->second < 6) {
                cout << "NO" << endl;
                continue;
            } else {
                int p = pf.begin()->first;
                a = p, b = p * p, c = n / p / p / p;
            }
        } else {
            auto itr = pf.begin();
            a = itr->first;
            itr++;
            b = itr->first;
            c = n / a / b;
            if (c == 1 || c == a || c == b) {
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }
}
