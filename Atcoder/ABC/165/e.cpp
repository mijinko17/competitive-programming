#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, m;

int main() {
    cin >> n >> m;
    int offset = 0;
    if (n % 2 != 0) {
        for (int i = 0; i < m; i++) {
            cout << i + 1 << ' ' << n - i << endl;
        }
        return 0;
    } else {
        for (int i = 0; i < m; i++) {
            int left = i + 1, right = n - i - offset;
            if (right - left == n / 2) {
                offset += 1;
                right--;
            }
            cout << left << ' ' << right << endl;
        }
    }
}
