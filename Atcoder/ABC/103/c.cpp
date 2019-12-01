#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = -n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans << endl;
}
