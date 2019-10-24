#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> count(2, 0);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            count[0]++;
        } else {
            count[1]++;
        }
    }
    cout << min(count[0], count[1]) * 2 << endl;
}
