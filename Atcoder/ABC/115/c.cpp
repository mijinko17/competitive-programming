#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(all(h));
    int ans = 1e+9 + 1;
    // i~i+k-1を飾ると思う
    for (int i = 0; i < n - k + 1; i++) {
        ans = min(ans, h[i + k - 1] - h[i]);
    }
    cout << ans << endl;
}
