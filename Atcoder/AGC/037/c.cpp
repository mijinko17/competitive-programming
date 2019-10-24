#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

//円形リスト
template <typename Num>
struct circle {
    vector<Num> c;
    long long int _l;
    circle(long long int l) : _l(l) {
        c = vector<Num>(l);
    }
    Num& operator[](int k) {
        int temp = k % _l;
        if (temp < 0) temp += _l;
        return c[temp];
    }
};

int main() {
    int n;
    cin >> n;
    circle<lint> a(n), b(n);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] != b[i]) {
            pq.push(make_pair(b[i], i));
        }
    }
    lint ans = 0;
    while (pq.size() > 0) {
        pair<int, int> now = pq.top();
        pq.pop();
        lint neighbor = b[now.second - 1] + b[now.second + 1];
        lint temp = (b[now.second] - a[now.second]) / neighbor;
        ans += temp;
        b[now.second] -= temp * neighbor;
        if (b[now.second] == a[now.second]) {
            continue;
        } else if (b[now.second] >= b[now.second - 1] &&
                   b[now.second] >= b[now.second + 1]) {
            cout << -1 << endl;
            return 0;
        } else {
            pq.push(make_pair(b[now.second], now.second));
        }
    }
    cout << ans << endl;
}
