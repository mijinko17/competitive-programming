#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double sum = 0;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
    }
    while (1) {
        for (int i = 0; i < n - 1; i++) {
            int x_dist = x[perm[i + 1] - 1] - x[perm[i] - 1];
            int y_dist = y[perm[i + 1] - 1] - y[perm[i] - 1];
            sum += sqrt(x_dist * x_dist + y_dist * y_dist);
        }
        if (!next_permutation(all(perm))) break;
    }
    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }
    cout << setprecision(10) << sum / fac << endl;
}
