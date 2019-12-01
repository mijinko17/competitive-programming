#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans = "";
    if (n == 0) {
        ans = "0";
    } else {
        while (n != 0) {
            if (n % 2 == 0) {
                ans = '0' + ans;
            } else {
                n--;
                ans = '1' + ans;
            }
            n /= -2;
        }
    }
    cout << ans << endl;
}
