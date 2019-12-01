#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length() + 1;
    //左に<が何個あるか、右に>が何個あるか
    vector<int> left(n), right(n);
    // left
    left[0] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '<') {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 0;
        }
    }
    // right
    right[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '>') {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 0;
        }
    }
    lint a = 0;
    for (int i = 0; i < n; i++) {
        a += max(left[i], right[i]);
    }
    cout << a << endl;
}
