#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<vector<int>> ope(k + 2, vector<int>());
    int ope_min = 0;
    int ope_max = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[j] == 'R' && s[j + 1] == 'L') {
                ope[i].push_back(j);
                s[j] = 'L';
                s[j + 1] = 'R';
                j++;
            }
        }
        if (ope[i].size() == 0) {
            ope_min = i;
            break;
        } else {
            if (i == k) {
                ope_min = k + 1;
            }
            ope_max += ope[i].size();
        }
    }
    lint count = 0;
    if (k >= ope_min && k <= ope_max) {
        int extend = k - ope_min;
        for (auto e : ope) {
            for (int i = 0; i < e.size(); i++) {
                if (extend > 0) {
                    cout << 1 << ' ' << e[i] + 1 << endl;
                    count++;
                    extend--;
                    if (count >= k) {
                        return 0;
                    }
                } else {
                    cout << (int)e.size() - i << ' ';
                    count += (int)e.size() - i;
                    for (int j = i; j < e.size(); j++) {
                        cout << e[j] + 1 << (j == e.size() - 1 ? "" : " ");
                    }
                    cout << endl;
                    if (count >= k) {
                        return 0;
                    }
                    break;
                }
            }
        }
    } else {
        cout << -1 << endl;
    }
}
