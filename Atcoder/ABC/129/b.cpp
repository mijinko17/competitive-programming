#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    // left:[0,n),right:[i,n)
    vector<int> left(n + 1, 0), right(n + 1, 0);
    for (int i = 0; i < n; i++) {
        left[i + 1] = left[i] + w[i];
        right[i] = sum - left[i];
    }
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(left[i] - right[i]));
    }
    cout << ans << endl;
}
