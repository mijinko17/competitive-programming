#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string a;
    cin >> a;
    lint n = a.size();
    unordered_map<char, lint> count;
    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }
    lint ans = n * (n - 1) / 2 + 1;
    for (auto itr = count.begin(); itr != count.end(); itr++) {
        auto now = (*itr).second;
        ans -= now * (now - 1) / 2;
    }
    cout << ans << endl;
}
