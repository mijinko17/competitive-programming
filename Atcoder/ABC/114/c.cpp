#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    // first:数、second:7,5,3が使われてるかどうかをビットで管理
    queue<pair<lint, int>> bfs;
    bfs.push({7, 1});
    bfs.push({5, 2});
    bfs.push({3, 4});
    int ans = 0;
    while (bfs.size() > 0) {
        auto now = bfs.front();
        bfs.pop();
        lint x = now.first, b = now.second;
        if (x > n) continue;
        if (b == 7) ans++;
        bfs.push({x * 10 + 7, b | 1});
        bfs.push({x * 10 + 5, b | 2});
        bfs.push({x * 10 + 3, b | 4});
    }
    cout << ans << endl;
}
