#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a;

void ope() {
    auto m = max_element(a.begin(), a.end());
    (*m) -= n + 1;
    for (auto &e : a) e++;
    sort(a.begin(), a.end());
    for (auto e : a) cout << e << " ";
    cout << endl;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (auto e : a) cout << e << " ";
    cout << endl;
    while (a.back() >= n) {
        ope();
    }
}
