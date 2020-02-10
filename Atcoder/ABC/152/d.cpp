#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

int getDigit(int num) {
    return to_string(num).length();
}

// a^nを計算　O(log n)
long long int powint(long long int a, long long int n) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = powint(a, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * a;
        }
    }
}

int main() {
    cin >> n;
    int k = getDigit(n);
    string s = to_string(n);
    vector<vector<lint>> count(10, vector<lint>(10));
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << i << " " << j << " " << s[0] << s.back() << endl;
            if (i < s[0] - '0') {
                lint add = 1;
                for (int z = 0; z <= k - 2; z++) {
                    count[i][j] += add;
                    add *= 10;
                }
            } else if (i > s[0] - '0') {
                lint add = 1;
                for (int z = 0; z <= k - 3; z++) {
                    count[i][j] += add;
                    add *= 10;
                }
            } else {
                lint add = 1;
                for (int z = 0; z <= k - 3; z++) {
                    count[i][j] += add;
                    add *= 10;
                }
                if (s.back() - '0' >= j) {
                    count[i][j] += stoi(s.substr(1, k - 2)) + 1;
                } else {
                    count[i][j] += stoi(s.substr(1, k - 2));
                }
            }
            cout << count[i][j] << endl;
        }
    }
    lint ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j < 9; j++) {
            ans += count[i][j] * count[j][i];
        }
    }
    cout << ans << endl;
}
