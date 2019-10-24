#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    vector<string> s = {"NO", "YES"};
    lint n;
    cin >> n;
    vector<lint> a(n + 1);
    lint sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    a[n] = a[0];
    // num_op:操作の合計回数
    lint num_op = sum / (n * (n + 1) / 2);
    // op[i]:iが操作で選ばれるべき回数
    vector<lint> op(n, 0);
    for (int i = 0; i < n; i++) {
        int expect = a[i] + num_op;
        if (a[i + 1] > expect || (a[i + 1] - expect) % n != 0) {
            cout << s[0] << endl;
            return 0;
        } else {
            op[i] = (expect - a[i + 1]) / n;
        }
    }
    //必要条件として求めた操作回数でa[0]が実現できるか見る
    lint test = 0;
    for (int i = 1; i <= n; i++) {
        test += op[n - i] * i;
    }
    if (test == a[0]) {
        cout << s[1] << endl;
    } else {
        cout << s[0] << endl;
    }
    return 0;
}
