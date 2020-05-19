#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;

int main() {
    cin >> n >> m;
    int offset = 0;
    vector<pair<int, int>> cand(m);
    if (n % 2 != 0) {
        for (int i = 0; i < m; i++) {
            cout << i + 1 << ' ' << n - i << endl;
        }
        return 0;
    } else {
        set<int> match;
        for (int i = 0; i < m; i++) {
            int left = i + 1, right = n - i - offset;
            if (right - left == n / 2) {
                offset += 1;
                right--;
            }
            int now = min(right - left, left + n - right);
            if (match.count(now)) {
                offset += 1;
                right--;
            }
            int now2 = min(right - left, left + n - right);
            match.insert(now2);
            cout << left << ' ' << right << endl;
        }
    }
}
