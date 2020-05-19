#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
map<int, int> even, odd;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (i % 2 == 0) {
            even[temp]++;
        } else {
            odd[temp]++;
        }
    }
}
