#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n, x;

lint burger_size(lint m) {
    return (1LL << (m + 2)) - 3;
}

lint all_paty(lint m) {
    return (1LL << (m + 1)) - 1;
}

// レベルmバーガーの下からy枚に何枚パティがあるか
lint dfs(lint m, lint y) {
    if (y == 0) {
        return 0;
    }
    if (y == burger_size(m)) {
        return all_paty(m);
    }
    lint res = 0;
    y--;
    res += dfs(m - 1, min(burger_size(m - 1), y));
    y -= min(burger_size(m - 1), y);
    if (y == 0) {
        return res;
    }
    y--, res++;
    res += dfs(m - 1, min(burger_size(m - 1), y));
    return res;
}

int main() {
    cin >> n >> x;
    cout << dfs(n, x) << endl;
}
