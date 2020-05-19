#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m, q;
vector<int> a, b, c, d;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int check(vector<int> hoge) {
    int res = 0;
    for (int i = 0; i < q; i++) {
        if (hoge[b[i]] - hoge[a[i]] == c[i]) {
            res += d[i];
        }
    }
    return res;
}

int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }
    queue<vector<int>> cand;
    for (int i = 1; i <= m; i++) {
        cand.push(vector<int>(1, i));
    }
    int ans = 0;
    while (!cand.empty()) {
        auto now = cand.front();
        cand.pop();
        if (now.size() == n) {
            chmax(ans, check(now));
        } else {
            for (int i = now.back(); i <= m; i++) {
                auto next = now;
                next.push_back(i);
                cand.push(next);
            }
        }
    }
    cout << ans << endl;
}
