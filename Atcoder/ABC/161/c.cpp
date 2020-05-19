#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    lint n, k;
    cin >> n >> k;
    n %= k;
    cout << min(n, abs(n - k)) << endl;
}
