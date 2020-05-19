#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n;

vector<string> s;

void dfs(string str, char c) {
    if (str.length() == n) {
        s.push_back(str);
    } else {
        int m = c - 'a';
        for (int i = 0; i <= m; i++) {
            dfs(str + (char)('a' + i), c);
        }
        if (c != 'z') {
            dfs(str + (char)('a' + m + 1), (char)(c + 1));
        }
    }
}

int main() {
    cin >> n;
    dfs("a", 'a');
    sort(s.begin(), s.end());
    for (auto e : s) {
        cout << e << endl;
    }
}
