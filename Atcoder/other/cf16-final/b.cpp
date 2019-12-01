#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    while (ans * (ans + 1) / 2 < n) ans++;
    int max = ans * (ans + 1) / 2;
    for (int i = 1; i <= ans; i++)
        if (i != max - n) cout << i << endl;
    return 0;
}
