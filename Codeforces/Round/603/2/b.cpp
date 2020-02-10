#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;
        int ans = 0;
        vector<string> p(n);
        unordered_map<string, int> dict;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            dict[p[i]]++;
            if (dict[p[i]] > 1) {
                ans++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (dict[p[i]] <= 1) {
                continue;
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 10; k++) {
                    string cand;
                    cand = p[i];
                    cand[j] = '0' + k;
                    if (dict[cand] == 0) {
                        dict[p[i]]--;
                        p[i] = cand;
                        dict[p[i]]++;
                        break;
                    }
                }
                if (dict[p[i]] <= 1) {
                    break;
                }
            }
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << p[i] << endl;
        }
    }
}
