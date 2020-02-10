#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a;

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint sum = a[0];
    lint cost = 0;
    for (int i = 1; i < n; i++) {
        if ((sum < 0 && sum + a[i] > 0) || (sum > 0 && sum + a[i] < 0)) {
            sum += a[i];
        } else {
            if (sum > 0) {
                cost += abs(sum + a[i] - (-1));
                sum = -1;
            } else {
                cost += abs(sum + a[i] - 1);
                sum = 1;
            }
        }
    }
    cout << cost << endl;
}
