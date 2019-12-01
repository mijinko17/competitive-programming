#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        q[i] = p[i];
    }
    sort(all(q));
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != q[i]) {
            count++;
        }
    }
    if (count <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
