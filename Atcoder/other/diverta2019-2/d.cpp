#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b);
template <class T>
bool chmin(T &a, const T &b);

int main() {
    int n;
    vector<lint> ga(3), gb(3);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> ga[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> gb[i];
    }
    // dp1[i]:=iどんぐり使った時の価値最大
    vector<lint> dp1(n + 1, n);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (j + ga[i] <= n) {
                chmax(dp1[j + ga[i]], dp1[j] + gb[i] - ga[i]);
            }
        }
    }
    lint m = *max_element(all(dp1));
    vector<lint> dp2(m + 1, m);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < m; j++) {
            if (j + gb[i] <= m) {
                chmax(dp2[j + gb[i]], dp2[j] + ga[i] - gb[i]);
            }
        }
    }
    cout << *max_element(all(dp2)) << endl;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
