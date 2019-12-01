#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < 10 && b < 10) {
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }
}
