#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> a;

int main() {
    cin >> n;
    a.resize(n + 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i + 1];
    }
    // left[i]:[0,i]を訪れるときの合計
    vector<int> left(n + 2, 0);
    for (int i = 0; i < n + 1; i++) {
        left[i + 1] = left[i] + abs(a[i + 1] - a[i]);
    }
    // right[i]:[i,n+1]を訪れるときの合計
    vector<int> right(n + 2, 0);
    for (int i = n + 1; i > 0; i--) {
        right[i - 1] = right[i] + abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << left[i - 1] + right[i + 1] + abs(a[i - 1] - a[i + 1]) << endl;
    }
}
