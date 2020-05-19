#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isTrivial(pair<int, int> p, pair<int, int> q) {
    return p.first <= q.first && p.second <= q.second;
}
bool isNonsense(pair<int, int> p, pair<int, int> q) {
    return p.first >= q.first && p.second >= q.second;
}

pair<int, int> rate(pair<int, int> p, pair<int, int> q) {
    auto res = make_pair(abs(p.first - q.first), abs(p.second - q.second));
    int div = gcd(res.first, res.second);
    res.first /= div, res.second /= div;
    return res;
}

//第一項が小さい
bool compare(pair<int, int> r1, pair<int, int> r2) {
    return r1.first * r2.second < r1.second * r2.first;
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int n;
        cin >> n;
        vector<pair<int, int>> cj(n);
        for (int i = 0; i < n; i++) {
            cin >> cj[i].first >> cj[i].second;
        }
        //(cの重さ,jの重さ):=(x,y)
        // y/xを見る
        // first:分子
        pair<int, int> low = {0, 1}, high = {1, 0};
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            if (isNonsense(cj[i], cj[i + 1])) {
                valid = false;
                break;
            }
            if (isTrivial(cj[i], cj[i + 1])) {
                continue;
            }
            auto r = rate(cj[i], cj[i + 1]);
            if (cj[i].first > cj[i + 1].first) {
                if (compare(low, r)) {
                    low = r;
                }
            } else {
                if (compare(r, high)) {
                    high = r;
                }
            }
        }
        if (!compare(low, high)) {
            valid = false;
        }
        if (!valid) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else {
            int x, y;
            bool exist_lower_bound = low != make_pair(0, 1);
            bool exist_upper_bound = high != make_pair(1, 0);
            if (!exist_lower_bound && !exist_upper_bound) {
                x = y = 1;
            } else if (!exist_lower_bound) {
                x = (high.second + 1 + high.first - 1) / high.first;
                y = 1;
            } else if (!exist_upper_bound) {
                x = 1;
                y = (low.first + 1 + low.second - 1) / low.second;
            } else {
                x = 1;
                while (1) {
                    int adx = low.first * high.second * x;
                    int bcx = low.second * high.first * x;
                    int bd = low.second * high.second;
                    int cand = (adx + 1 + bd - 1) / bd;
                    if (cand * bd < bcx) {
                        y = cand;
                        break;
                    }
                    x++;
                }
            }
            cout << x << ' ' << y << endl;
        }
    }
    return 0;
}
