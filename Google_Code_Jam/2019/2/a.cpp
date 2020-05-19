#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//最大公約数の計算(ユークリッドの互除法)
long long int gcd(long long int a, long long int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isObvious(pair<int, int> a, pair<int, int> b) {
    return (a.first <= b.first && a.second <= b.second) ||
           (a.first >= b.first && a.second >= b.second);
}

pair<int, int> rate(pair<int, int> a, pair<int, int> b) {
    pair<int, int> res(abs(a.first - b.first), abs(a.second - b.second));
    int div = gcd(res.first, res.second);
    res.first /= div, res.second /= div;
    return res;
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
        set<pair<int, int>> count;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!isObvious(mol[i], mol[j])) {
                    count.insert(rate(mol[i], mol[j]));
                }
            }
        }
        cout << count.size() + 1 << endl;
    }
    return 0;
}
