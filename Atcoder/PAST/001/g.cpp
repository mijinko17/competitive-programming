#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// a^nを計算　O(log n)
long long int powint(long long int a, long long int n) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = powint(a, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * a;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<lint>> a(n, vector<lint>(n));
    lint sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    lint M = powint(3, n);
    lint ans = sum;
    for (int i = 0; i < M; i++) {
        vector<int> group(n);
        int key = i;
        for (int j = 0; j < n; j++) {
            group[j] = key % 3;
            key /= 3;
        }
        lint cand = 0;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (group[j] == group[k]) {
                    cand += a[j][k];
                }
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
}
