#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

lint GetDigit(lint num) {
    return std::to_string(num).length();
}

lint value(lint n, lint a, lint b) {
    return a * n + b * GetDigit(n);
}

int main() {
    lint a, b, x;
    cin >> a >> b >> x;
    lint ok = 0, no = 1e+9 + 1;
    while (abs(ok - no) > 1) {
        lint mid = (ok + no) / 2;
        if (value(mid, a, b) <= x) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    cout << ok << endl;
}
