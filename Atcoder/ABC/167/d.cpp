#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, k;
vector<lint> a;

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> doubling(n, vector<int>(65));
    for (int i = 0; i < n; i++) {
        doubling[i][0] = a[i];
    }
    for (int i = 1; i <= 64; i++) {
        for (int j = 0; j < n; j++) {
            doubling[j][i] = doubling[doubling[j][i - 1]][i - 1];
        }
    }
    bitset<65> bit(k);
    int now = 0;
    for (int i = 0; i < 64; i++) {
        if (bit[i]) {
            now = doubling[now][i];
        }
    }
    cout << now + 1 << endl;
}
