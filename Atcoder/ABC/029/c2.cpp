#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

void dfs(string s) {
    if (s.length() == n) {
        cout << s << endl;
    } else {
        dfs(s + 'a');
        dfs(s + 'b');
        dfs(s + 'c');
    }
}

int main() {
    cin >> n;
    dfs("");
}
