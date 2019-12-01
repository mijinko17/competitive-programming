#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    set<string> cands;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + i <= s.length(); j++) {
            cands.insert(s.substr(j, i));
        }
    }
    auto itr = cands.begin();
    for (int i = 0; i < k - 1; i++) {
        itr++;
    }
    cout << (*itr) << endl;
}
