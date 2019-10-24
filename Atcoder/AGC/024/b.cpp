#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    int temp = 1;
    int l = 1;
    for (int i = 0; i < n - 1; i++) {
        if (q[i] < q[i + 1]) {
            temp++;
            l = max(l, temp);
        } else {
            temp = 1;
        }
    }
    cout << n - l << endl;
}
