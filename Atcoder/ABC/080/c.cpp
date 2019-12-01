#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

//立ってるビットの本数
int cardinal(int n) {
    int res = 0;
    while (n > 0) {
        if (n & 1) res++;
        n >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> isOpen(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                isOpen[i] |= (1 << j);
            }
        }
    }
    vector<vector<int>> p(n, vector<int>(11));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }
    int ans = -1e+9 - 1;
    for (int i = 1; i < (1 << 10); i++) {
        int temp = 0;
        for (int j = 0; j < n; j++) {
            temp += p[j][cardinal(i & isOpen[j])];
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
