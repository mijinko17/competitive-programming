#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        lint A, B;
        cin >> A >> B;
        lint k = 0;
        lint temp = 10;
        while (B >= temp - 1) {
            k++;
            temp *= 10;
        }
        cout << k * A << endl;
    }
}
