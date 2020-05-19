#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        count[a]++;
    }
    for (auto e : count) {
        cout << e << endl;
    }
}
