#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    int ans = -1;
    for (int i = l; i <= r; i++) {
        bool flag = true;
        vector<int> v(10, 0);
        int temp = i;
        while (temp > 0) {
            if (v[temp % 10] == 0) {
                v[temp % 10]++;
                temp /= 10;
            } else {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
