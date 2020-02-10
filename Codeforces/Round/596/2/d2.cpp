#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// 奇素因数のみの積
lint odd_part(long long int n) {
    lint res = 1;
    for (long long int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0 && count % 2 == 1) {
            res *= i;
        }
    }
    if (n != 1) res *= n;
    return res;
}

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
    if (k == 2) {
        unordered_map<lint, int> count;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            count[odd_part(a)]++;
        }
        lint ans = 0;
        for (auto itr = count.begin(); itr != count.end(); itr++) {
            auto now = (*itr).second;
            ans += now * (now - 1) / 2;
        }
        cout << ans << endl;
    } else {
        vector<lint> a(n);
        unordered_map<lint, int> count;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            count[a[i]]++;
        }
        lint ans = 0;
        for (int i = 1; powint(i, k) <= 1e10; i++) {
            lint target = powint(i, k);
            for (int j = 0; j < n; j++) {
                if (target % a[j] == 0) {
                    ans += count[target / a[j]];
                    if (target == a[j] * a[j]) {
                        ans--;
                    }
                }
            }
        }
        cout << ans / 2 << endl;
    }
}
