#include <bits/stdc++.h>
using namespace std;

//素因数分解unordered_map版　O(√n)
template <typename T>
unordered_map<T, T> pf_um(T n) {
    unordered_map<T, T> res;
    for (long long int i = 2; i * i <= n; i++)
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    if (n != 1) res[n]++;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> plist(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        unordered_map<int, int> t = pf_um(i);
        for (auto itr = t.begin(); itr != t.end(); itr++) {
            pair<int, int> factor = (*itr);
            plist[factor.first] += factor.second;
        }
    }
    long long int ans = 0;
    // 75
    for (int i = 2; i <= n; i++) {
        if (plist[i] >= 74) {
            ans++;
        }
    }
    for (int i = 2; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // 3*25
            if (plist[i] >= 2 && plist[j] >= 24) {
                ans++;
            }
            if (plist[j] >= 2 && plist[i] >= 24) {
                ans++;
            }
            // 5*15
            if (plist[i] >= 4 && plist[j] >= 14) {
                ans++;
            }
            if (plist[j] >= 4 && plist[i] >= 14) {
                ans++;
            }
        }
    }
    // 3*5*5
    for (int i = 2; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (plist[i] >= 2 && plist[j] >= 4 && plist[k] >= 4) {
                    ans++;
                }
                if (plist[k] >= 2 && plist[i] >= 4 && plist[j] >= 4) {
                    ans++;
                }
                if (plist[j] >= 2 && plist[k] >= 4 && plist[i] >= 4) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
