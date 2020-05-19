#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m, k;
string d;
vector<string> s;

int p2i(int x, int y) {
    return x * m + y;
}

int main() {
    cin >> n >> m >> k >> d;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    d = d + d;
    //{U,D,L,R}={0,1,2,3}
    vector<vector<int>> next_D(k, vector<int>(4));
    vector<vector<lint>> dist(n * m);
}
