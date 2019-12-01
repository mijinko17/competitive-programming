#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
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
    int n, k;
    cin >> n >> k;
    vector<lint> a(n);
    lint M = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        M = max(M, a[i]);
    }
    int m = pow(10000000000, 1.0 / k);
    vector<lint> pows;
    for (int i = 0; i < m; i++) {
        pows.push_back(powint(i + 1, k));
    }
    unordered_map<lint, lint> count;
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto itr = lower_bound(all(pows), a[i]); itr != pows.end();
             itr++) {
            if (*itr / a[i] > M) {
                break;
            }
            if (*itr % a[i] == 0) {
                count[*itr / a[i]]++;
                if (*itr / a[i] == a[i]) {
                    ans--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans += count[a[i]];
    }
    cout << ans / 2 << endl;
}
