#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

char sw(char test, char before, char now) {
    if ((test == 'o' && now == 'S') || (test == 'x' && now == 'W')) {
        return before;
    } else {
        return before == 'S' ? 'W' : 'S';
    }
}

string candidate(string s, char i0, char i1) {
    string res(s.length(), ' ');
    res[0] = i0, res[1] = i1;
    for (int i = 2; i < s.length(); i++) {
        res[i] = sw(s[i - 1], res[i - 2], res[i - 1]);
    }
    return res;
}

bool isVarid(string s, string cand) {
    return cand == candidate(s + s, cand[0], cand[1]).substr(s.length());
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    string SS = candidate(s, 'S', 'S');
    if (isVarid(s, SS)) {
        cout << SS << endl;
        return 0;
    }
    string SW = candidate(s, 'S', 'W');
    if (isVarid(s, SW)) {
        cout << SW << endl;
        return 0;
    }
    string WS = candidate(s, 'W', 'S');
    if (isVarid(s, WS)) {
        cout << WS << endl;
        return 0;
    }
    string WW = candidate(s, 'W', 'W');
    if (isVarid(s, WW)) {
        cout << WW << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
