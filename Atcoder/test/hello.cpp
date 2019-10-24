#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    vector<string> s(5);
    s[3] += 'a';
    for (int i = 0; i < 5; i++) {
        cout << s[i] << endl;
    }
}
