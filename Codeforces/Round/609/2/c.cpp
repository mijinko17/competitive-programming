#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string increment(string s) {
    int target = ((int)s.length()) - 1;
    while (s[target] == '9') {
        s[target] = '0';
        target--;
    }
    s[target] += 1;
    return s;
}

int main() {
    int n, k;
    string a;
    cin >> n >> k >> a;
    int m = ((n + k - 1) / k) * k;
    a = a + string(m - n, '0');
    string top = a.substr(0, k);
    // flag:toptoptop...とできるか
    bool flag = true;
    for (int i = 0; i < m / k; i++) {
        string sub = a.substr(i * k, k);
        if (sub < top) {
            break;
        } else if (sub > top) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        top = increment(top);
    }
    string ans = "";
    for (int i = 0; i < m / k; i++) {
        ans += top;
    }
    cout << n << endl;
    cout << ans.substr(0, n) << endl;
}
