#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int n, z, w;
vector<int> a;

int main() {
    cin >> n >> z >> w;
    if (n == 1) {
        int b;
        cin >> b;
        cout << abs(b - w) << endl;
        return 0;
    }
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    // dpz[i]:zが残りi枚でターンが回ってきたときのスコア
    vector<int> dpx(n + 1, INT_MIN);
    vector<int> dpy(n + 1, INT_MAX);
    dpx[1] = dpy[1] = abs(a[1] - a[0]);
    for (int i = 2; i <= n; i++) {
        // j枚引く
        for (int j = 1; j < i; j++) {
            chmax(dpx[i], dpy[j]);
            chmin(dpy[i], dpx[j]);
        }
        //全部引く
        if (i == n) {
            chmax(dpx[i], abs(w - a[0]));
            chmin(dpy[i], abs(z - a[0]));

        } else {
            chmax(dpx[i], abs(a[i] - a[0]));
            chmin(dpy[i], abs(a[i] - a[0]));
        }
    }
    cout << dpx[n] << endl;
    return 0;
}
