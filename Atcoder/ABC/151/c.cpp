#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> ac(n, false);
    vector<int> wa(n, 0);
    for (int i = 0; i < m; i++) {
        int p;
        string s;
        cin >> p >> s;
        p--;
        if (s == "AC") {
            ac[p] = true;
        } else {
            if (!ac[p]) {
                wa[p]++;
            }
        }
    }
    lint num_ac = 0;
    lint num_wa = 0;
    for (int i = 0; i < n; i++) {
        if (ac[i]) {
            num_ac++;
            num_wa += wa[i];
        }
    }
    cout << num_ac << " " << num_wa << endl;
}
