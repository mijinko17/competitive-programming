#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

bool rg(char a, char b) {
    return (a == 'R' && b == 'G') || (a == 'G' && b == 'R');
}
bool gb(char a, char b) {
    return (a == 'G' && b == 'B') || (a == 'B' && b == 'G');
}
bool br(char a, char b) {
    return (a == 'B' && b == 'R') || (a == 'R' && b == 'B');
}

// 累積和
struct cumulative_sum {
    using lint = long long int;
    int sz;
    // data[i]:元の数列
    vector<lint> data;
    // cum[i]:[0,i)の和
    vector<lint> sum;
    // 要素数を指定して初期化
    cumulative_sum(const int _sz) : sz(_sz) {
        data.assign(sz, 0);
        sum.assign(sz + 1, 0);
    }
    lint& operator[](const int k) {
        return data[k];
    }
    // dataに基づいてsumを構築
    void build() {
        for (int i = 0; i < sz; i++) sum[i + 1] = sum[i] + data[i];
    }
    // [a,b)の和を求める
    lint query(const int a, const int b) {
        return sum[b] - sum[a];
    }
};

int main() {
    int n;
    string s;
    cin >> n >> s;
    cumulative_sum r(n), g(n), b(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            r[i] = 1;
        }
        if (s[i] == 'G') {
            g[i] = 1;
        }
        if (s[i] == 'B') {
            b[i] = 1;
        }
    }
    r.build();
    g.build();
    b.build();
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (rg(s[i], s[j])) {
                ans += b.query(j + 1, n);
                int d = 2 * j - i;
                if (d < n && s[d] == 'B') {
                    ans--;
                }
            }
            if (gb(s[i], s[j])) {
                ans += r.query(j + 1, n);
                int d = 2 * j - i;
                if (d < n && s[d] == 'R') {
                    ans--;
                }
            }
            if (br(s[i], s[j])) {
                ans += g.query(j + 1, n);
                int d = 2 * j - i;
                if (d < n && s[d] == 'G') {
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
}
