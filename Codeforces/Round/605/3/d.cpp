#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // left[i]:[x,i)が単調増加なる最長の部分列の長さ
    vector<int> left(n + 1);
    left[0] = 0;
    left[1] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            left[i + 1] = left[i] + 1;
        } else {
            left[i + 1] = 1;
        }
    }
    // right[i]:[i,x)が単調増加なる最長の部分列の長さ
    vector<int> right(n + 1);
    right[n] = 0;
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 1;
        }
    }
    int ans = 0;
    //抜かない
    for (int i = 0; i < n; i++) {
        chmax(ans, left[i + 1] + right[i] - 1);
    }
    //抜く
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i + 1]) {
            chmax(ans, left[i] + right[i + 1]);
        }
    }
    cout << ans << endl;
}
