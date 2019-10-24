#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int d(int a) {
    return a * 2;
}

int main() {
    function<int(int)> f = d;
    cout << f(5) << endl;
}
