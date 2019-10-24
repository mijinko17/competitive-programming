#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << max(0, a - 2 * b) << endl;
}
