#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long int invariant = 0;
    long long int numW = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'W') {
            numW++;
            invariant += i;
        }
    }
    cout << invariant - numW * (numW - 1) / 2 << endl;
}
