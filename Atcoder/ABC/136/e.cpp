#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    lint sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    //候補を列挙
    vector<int> factor;
    for (lint i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            factor.push_back(i);
            if (i * i != sum) {
                factor.push_back(sum / i);
            }
        }
    }
    sort(all(factor), greater<int>());
    lint ans = 1;
    for (int i = 0; i < factor.size(); i++) {
        vector<int> mod(n);
        lint dist = 0;
        for (int j = 0; j < n; j++) {
            mod[j] = a[j] % factor[i];
            dist += mod[j];
        }
        sort(all(mod), greater<int>());
        // fac,...fac,0,...,0にしたい
        // block:facの数
        lint block = dist / factor[i];
        lint s = 0;
        for (int j = 0; j < block; j++) {
            s += mod[j];
        }
        if (block * factor[i] - s <= k) {
            ans = factor[i];
            break;
        }
    }
    cout << ans << endl;
}
