#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<lint> a;
lint l, r;

pair<lint, int> happiness(int x) {
    return max(abs(x - l), abs(x - r)) * a[x];
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> remain(n, false);
    vector<bool> used(n, false);
    l = 0;
    r = n - 1;
    for (int i = 0; i < n; i++) {
        int from, to;
        lint h = -1;
    }
}
