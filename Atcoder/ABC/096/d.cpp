#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

//エラトステネスの篩
vector<bool> eratosthenes_sieve(int n) {
    vector<bool> res(n + 1, true);
    res[0] = res[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (res[i]) {
            for (int j = i; i * j <= n; j++) res[i * j] = false;
        }
    }
    return res;
}

int main() {
    cin >> n;
    auto p = eratosthenes_sieve(55555);
    int now = 2;
    while (n > 0) {
        if (p[now] && now % 5 == 1) {
            cout << now << endl;
            n--;
        }
        now++;
    }
}
