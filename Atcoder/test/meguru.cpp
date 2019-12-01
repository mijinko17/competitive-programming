#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

long long int meguru_BinarySearch(long long int ok, long long int no,
                                  function<bool(long long int)> isVarid,
                                  long long int diff = 1) {
    while (abs(ok - no) > diff) {
        int mid = (ok + no) / 2;
        if (isVarid(mid)) {
            ok = mid;
        } else {
            no = mid;
        }
    }
    return ok;
}

long long int getDigit(long long int num) {
    return to_string(num).length();
}

int main() {
    int a, b, x;
    cin >> a >> b >> x;
    auto judge = [=](lint n) { return a * n + b * getDigit(n) <= x; };
    cout << meguru_BinarySearch(0, 1e+9 + 1, judge) << endl;
    cout << getDigit(154534523) << endl;
}
