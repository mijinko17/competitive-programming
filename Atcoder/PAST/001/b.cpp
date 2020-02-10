#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
            cout << "up"
                 << " " << a[i + 1] - a[i] << endl;
        } else if (a[i + 1] < a[i]) {
            cout << "down"
                 << " " << a[i] - a[i + 1] << endl;
        } else {
            cout << "stay" << endl;
        }
    }
    return 0;
}
