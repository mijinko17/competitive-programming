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
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum <= s) {
            cout << 0 << endl;
            continue;
        }
        //[0,border)の和がsを超えない最大のやつ
        int border = 0;
        int sum2 = 0;
        while (sum2 + a[border] <= s) {
            sum2 += a[border];
            border++;
        }
        if (border == 0) {
            cout << 1 << endl;
            continue;
        }
        // m:ボーダー内で最大のやつ
        int m = a[0];
        int m_index = 0;
        for (int i = 1; i < border; i++) {
            if (chmax(m, a[i])) {
                m_index = i;
            }
        }
        if (a[m_index] > a[border]) {
            cout << m_index + 1 << endl;
        } else {
            cout << border + 1 << endl;
        }
    }
}
