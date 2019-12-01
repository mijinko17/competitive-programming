#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint ans = 0;
    int right = 0;
    lint sum = 0;
    for (int left = 0; left < n; left++) {
        while (right < n && sum + a[right] == (sum ^ a[right])) {
            sum += a[right];
            right++;
        }
        ans += right - left;
        if (left == right)
            right++;
        else
            sum -= a[left];
    }
    cout << ans << endl;
}
