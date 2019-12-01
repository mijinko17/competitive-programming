#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

// 最長非減少部分列の長さ
// type==false<=>狭義単調増加列の長さ
template <typename T>
int lis(const vector<T>& a, bool type = true) {
    int n = a.size();
    vector<long long int> dp(n, LLONG_MAX);
    for (int i = 0; i < n; i++) {
        auto itr = type ? upper_bound(dp.begin(), dp.end(), a[i])
                        : lower_bound(dp.begin(), dp.end(), a[i]);
        *itr = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), LLONG_MAX) - dp.begin();
}

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << lis(w, false) << endl;
}
