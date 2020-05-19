#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;

int main() {
    cin >> n;
    queue<string> bfs;
    bfs.push("");
    while (!bfs.empty()) {
        string s = bfs.front();
        bfs.pop();
        if (s.length() == n) {
            cout << s << endl;
        } else {
            bfs.push(s + 'a');
            bfs.push(s + 'b');
            bfs.push(s + 'c');
        }
    }
    return 0;
}
