#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int m, long long int n) {
    m = abs(m);
    n = abs(n);
    if (m * n == 0) {
        return max(m, n);
    } else {
        return gcd(min(m, n), max(m, n) % min(m, n));
    }
}

vector<long long int> pf(long long int n) {
    vector<long long int> res;
    for (long long int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
    if (n != 1) res.push_back(n);
    return res;
}

int main() {
    long long int a, b;
    cin >> a >> b;
    cout << pf(gcd(a, b)).size() + 1 << endl;
}
