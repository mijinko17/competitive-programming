#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint a, b, n;

lint f(lint x) {
    return a * x / b - a * (x / b);
}

int main() {
    cin >> a >> b >> n;
    cout << f(min(n, b - 1)) << endl;
}
