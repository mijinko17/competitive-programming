#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint k;

int main() {
    cin >> k;
    lint n = (k + 49) / 50 + 49;
    lint ex = (n - 49) * 50 - k;
    vector<lint> a(50, n);
    while (ex--) {
        auto m = max_element(a.begin(), a.end());
        for (auto itr = a.begin(); itr != a.end(); itr++) {
            if (itr == m) {
                (*itr) -= 50;
            } else {
                (*itr)++;
            }
        }
    }
    cout << 50 << endl;
    for (auto e : a) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
