#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int digit_sum(int x) {
    int res = 0;
    string s = to_string(x);
    for (auto e : s) {
        res += e - '0';
    }
    return res;
}

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    for (int j = 0; j < 20000; j++) {
        int m = INT_MAX;
        int ans;
        for (int i = j; i < j + 10000; i++) {
            if (chmin(m, digit_sum(i) + digit_sum(i - j))) {
                ans = i;
            }
        }
        cout << j << " " << ans << endl;
    }
}
