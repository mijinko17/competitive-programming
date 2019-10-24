#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    h[n] = 0;
    lint ans = 0;
    //各t:高さについて連結成分の個数を調べる
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < n; j++) {
            if (h[j] >= i && h[j + 1] < i) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
