#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * m * n - 2 * m - 2 * n) {
        cout << "NO" << endl;
        return 0;
    }
    if (m == 1) {
        cout << "YES" << endl;
        if (k > n - 1) {
            cout << 2 << endl;
            cout << n - 1 << " "
                 << "D" << endl;
            cout << k - (n - 1) << " "
                 << "U" << endl;
        } else {
            cout << 1 << endl;
            cout << k << " "
                 << "D" << endl;
        }
        return 0;
    }
    queue<pair<int, string>> que;
    int rem = k;
    if (rem > 0) {
        int num = min(m - 1, rem);
        que.push({num, "R"});
        rem -= num;
    }
    if (rem > 0) {
        int num = min(m - 1, rem);
        que.push({num, "L"});
        rem -= num;
    }
    for (int i = 0; i < n - 1; i++) {
        if (rem > 0) {
            que.push({1, "D"});
            rem--;
        }
        if (rem > 0) {
            int num = min(rem / 3, m - 1);
            string move = "RUD";
            if (num > 0) {
                que.push({num, move});
                rem -= num * 3;
            }
            if (num < m - 1 && rem > 0 && rem < 3) {
                que.push({1, move.substr(0, rem)});
                rem = 0;
            }
        }
        if (rem > 0) {
            int num = min(m - 1, rem);
            que.push({num, "L"});
            rem -= num;
        }
    }
    if (rem > 0) {
        int num = min(n - 1, rem);
        que.push({num, "U"});
    }
    cout << "YES" << endl;
    cout << que.size() << endl;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        cout << p.first << " " << p.second << endl;
    }
}
