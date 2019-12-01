#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string s_f = s.substr(0, n), s_b = s.substr(n);
    reverse(all(s_b));
    map<pair<string, string>, lint> sep_f, sep_b;
    //前の分割
    for (int i = 0; i < (1 << n); i++) {
        string temp_f = "", temp_b = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp_f = temp_f + s_f[j];
            } else {
                temp_b = temp_b + s_f[j];
            }
        }
        sep_f[make_pair(temp_f, temp_b)]++;
    }
    //後ろの分割
    for (int i = 0; i < (1 << n); i++) {
        string temp_f = "", temp_b = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp_b = temp_b + s_b[j];
            } else {
                temp_f = temp_f + s_b[j];
            }
        }
        sep_b[make_pair(temp_f, temp_b)]++;
    }
    lint ans = 0;
    for (auto itr = sep_f.begin(); itr != sep_f.end(); itr++) {
        auto now = (*itr);
        ans += now.second * sep_b[now.first];
    }
    cout << ans << endl;
}
