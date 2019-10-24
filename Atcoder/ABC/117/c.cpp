#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<lint> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    sort(all(x));
    vector<lint> d(m - 1);
    for (int i = 0; i < m - 1; i++) {
        d[i] = x[i + 1] - x[i];
    }
    sort(all(d), greater<lint>());
    lint shortcut = 0;
    for (int i = 0; i < n - 1 && i < m - 1; i++) {
        shortcut += d[i];
    }
    cout << x[m - 1] - x[0] - shortcut << endl;
}
