#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

void dfs_odd(int k, vector<int>& a, vector<int>& odd, vector<bool>& arrived) {
    arrived[k] = true;
    if (k - a[k] >= 0) {
        int down = k - a[k];
        if (!arrived[down]) {
            dfs_odd(down, a, odd, arrived);
        }
        chmin(odd[k], odd[down]);
        if (a[down] % 2 == 1) {
            odd[k] = 1;
        }
    }
    if (k + a[k] < a.size()) {
        int up = k + a[k];
        if (!arrived[up]) {
            dfs_odd(up, a, odd, arrived);
        }
        chmin(odd[k], odd[up]);
        if (a[up] % 2 == 1) {
            odd[k] = 1;
        }
    }
}
void dfs_even(int k, vector<int>& a, vector<int>& odd, vector<bool>& arrived) {
    arrived[k] = true;
    if (k - a[k] >= 0) {
        int down = k - a[k];
        if (!arrived[down]) {
            dfs_even(down, a, odd, arrived);
        }
        chmin(odd[k], odd[down]);
    }
    if (k + a[k] < a.size()) {
        int up = k + a[k];
        if (!arrived[up]) {
            dfs_even(up, a, odd, arrived);
        }
        chmin(odd[k], odd[up]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> odd(n, INT_MAX), even(n, INT_MAX);
    vector<bool> odd_arrived(n, false), even_arrived(n, false);
    for (int i = 0; i < n; i++) {
        dfs(i, a, odd, odd_arrived);
        dfs(i, a, even, even_arrived);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (odd[i] == INT_MAX) {
                cout << -1 << endl;
            } else {
                cout << odd[i] << endl;
            }
        } else {
            if (even[i] == INT_MAX) {
                cout << -1 << endl;
            } else {
                cout << even[i] << endl;
            }
        }
    }
}
