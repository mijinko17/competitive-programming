#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

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

int n, m;
vector<int> s;
vector<char> c;

int main() {
    cin >> n >> m;
    s.resize(m), c.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i] >> c[i];
    }
    int start = powint(10, n - 1), goal = powint(10, n);
    if (n == 1) {
        start = 0;
    }
    for (int i = start; i < goal; i++) {
        string num = to_string(i);
        bool judge = true;
        for (int j = 0; j < m; j++) {
            if (num[s[j] - 1] != c[j]) {
                judge = false;
                break;
            }
        }
        if (judge) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
