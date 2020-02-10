#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    vector<int> v(6);
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[3] << endl;
}
