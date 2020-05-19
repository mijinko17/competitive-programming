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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 0;
    do {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += a[p[i]] * abs(i - p[i]);
        }
        chmax(ans, temp);
        if (temp == 21) {
            for (int i = 0; i < n; i++) {
                cout << a[p[i]] << ' ' << ' ';
            }
            cout << endl;
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}
