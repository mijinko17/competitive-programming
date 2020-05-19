#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isObvious(pair<int, int> a, pair<int, int> b) {
    return (a.first <= b.first && a.second <= b.second);
}
bool isNonsense(pair<int, int> a, pair<int, int> b) {
    return (a.first >= b.first && a.second >= b.second);
}

pair<int, int> rate(pair<int, int> a, pair<int, int> b) {
    pair<int, int> res(abs(a.second - b.second), abs(a.first - b.first));
    int div = gcd(res.first, res.second);
    res.first /= div, res.second /= div;
    return res;
}

//第一項が小さい
bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second * b.first < a.first * b.second;
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int n;
        cin >> n;
        vector<pair<int, int>> mol(n);
        for (int i = 0; i < n; i++) {
            cin >> mol[i].first >> mol[i].second;
        }
        pair<int, int> lower = {1, 0}, upper = {0, 1};
        bool isValid = true;
        for (int i = 0; i < n - 1; i++) {
            if (isNonsense(mol[i], mol[i + 1])) {
                isValid = false;
                break;
            }
            if (isObvious(mol[i], mol[i + 1])) {
                continue;
            }
            auto r = rate(mol[i], mol[i + 1]);
            // lower
            if (mol[i].first > mol[i + 1].first) {
                if (compare(lower, r)) {
                    lower = r;
                }
            } else {
                if (compare(r, upper)) {
                    upper = r;
                }
            }
        }
        if (!isValid || !compare(lower, upper)) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            int x;
            int y;
            bool l = lower == make_pair(1, 0), u = upper == make_pair(0, 1);
            if (l && u) {
                x = y = 1;
            } else if (l) {
                x = (upper.first + upper.second) / upper.second * upper.second;
                y = 1;
            } else if (u) {
                x = (lower.second + lower.first) / lower.first * lower.first;
                y = 1;
            } else {
                x = 1;
                int p = lower.second * upper.first;
                int q = lower.first * upper.first;
                int r = lower.first * upper.second;
                while (1) {
                    int cand = (p * x + q) / q * q;
                    if (cand < r * x) {
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
