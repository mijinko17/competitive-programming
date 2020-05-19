#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, m;
vector<lint> a;

int main() {
    cin >> n >> m;
    a.resize(n);
    lint sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end(), greater<lint>());
    for (int i = 0; i < m; i++) {
        if (a[i] * 4 * m < sum) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
