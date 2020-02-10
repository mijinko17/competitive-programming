#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<int> a;

int main() {
    cin >> n;
    a.resize(n);
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[a[i]]++;
        if (count[a[i]] > 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
