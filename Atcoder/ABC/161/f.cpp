#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n;

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main() {
    cin >> n;
    auto div1 = divisor(n);
    auto div2 = divisor(n - 1);
    set<lint> ans;
    for (auto e : div1) {
        if (e == 1) {
            continue;
        }
        lint p = e;
        lint nn = n;
        while (nn % p == 0) {
            nn /= p;
        }
        if (nn % p == 1) {
            ans.insert(e);
        }
    }
    for (auto e : div2) {
        if (n % e != 0) {
            ans.insert(e);
        }
    }
    cout << ans.size() << endl;
}
