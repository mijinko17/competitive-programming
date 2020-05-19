#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> a;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = *max_element(a.begin(), a.end());
    int y = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) continue;
        if (min(a[i], x - a[i]) > min(y, x - y)) {
            y = a[i];
        }
    }
    cout << x << " " << y << endl;
}
