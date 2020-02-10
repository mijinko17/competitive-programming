#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int z = 0; z < T; z++) {
        int n;
        cin >> n;
        set<int> ans;
        ans.insert(0);
        //人数i人に対するスコア
        for (int i = 1; (i - 1) * (i - 1) <= n; i++) {
            ans.insert(n / i);
        }
        //スコアiなる人数があるか
        for (int i = 1; (i - 1) * (i - 1) <= n; i++) {
            if (n % i < n / i) {
                ans.insert(i);
            }
        }
        cout << ans.size() << endl;
        for (auto itr = ans.begin(); itr != ans.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;
    }
}
