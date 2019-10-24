#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

void yes() {
    cout << "Yes" << endl;
}
void no() {
    cout << "No" << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        count[temp]++;
        if (count[temp] == 1) {
            a.push_back(temp);
        }
    }
    if (a.size() > 2) {
        no();
    } else if (a.size() == 2) {
        int M = max(a[0], a[1]), m = min(a[0], a[1]);
        int k = count[m];
        if (M - m == 1) {
            if (M - k >= 1 && 2 * (M - k) <= n - k) {
                yes();
            } else {
                no();
            }
        } else {
            no();
        }
    } else {
        int m = a[0];
        if (m == n - 1 || 2 * m <= n) {
            yes();
        } else {
            no();
        }
    }
    return 0;
}
