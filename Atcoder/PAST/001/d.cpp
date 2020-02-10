#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> count(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] <= n) {
            count[a[i]]++;
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (count[i] != 1) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "Correct" << endl;
        return 0;
    }
    int dup = -1, no = -1;
    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            no = i;
        } else if (count[i] == 2) {
            dup = i;
        }
    }
    if (dup != -1) {
        cout << dup << " " << no << endl;
        return 0;
    } else {
        int e;
        for (int i = 0; i < n; i++) {
            if (a[i] < 1 || a[i] > n) {
                e = a[i];
            }
        }
        cout << e << " " << no << endl;
    }
}
