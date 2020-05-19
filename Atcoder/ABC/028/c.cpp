#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    vector<int> abc(5);
    for (int i = 0; i < 5; i++) {
        cin >> abc[i];
    }
    set<int> s;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                s.insert(abc[i] + abc[j] + abc[k]);
            }
        }
    }
    auto itr = s.rbegin();
    itr++;
    itr++;
    cout << *itr << endl;
}
