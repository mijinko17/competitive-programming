#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//体力nのモンスターを倒すのに必要な攻撃回数
lint solve(lint n) {
    if (n == 1) {
        return 1;
    } else {
        lint temp = solve(n / 2);
        return temp * 2 + 1;
    }
}

lint h;

int main() {
    cin >> h;
    cout << solve(h) << endl;
}
