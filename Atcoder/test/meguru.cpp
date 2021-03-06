#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// agc-041-b

lint n, m, v, p;
vector<lint> a;

// めぐる式二分探索
template <typename T>
T meguru_BinarySearch(T ok, T no, function<bool(T)> isValid, T diff = 1) {
    while (abs(ok - no) > diff) {
        T mid = (ok + no) / 2;
        (isValid(mid) ? ok : no) = mid;
        // if (isValid(mid))
        //     ok = mid;
        // else
        //     no = mid;
    }
    return ok;
}

// a[i]をp位以内にできるか
bool check(lint cand) {
    lint modi = a[cand] + m;
    if (modi < a[n - p]) {
        return false;
    }
    lint l = cand + 1, r = n - p + 1;
    lint limit = 0;
    for (int i = l; i < r; i++) {
        limit += min(m, modi - a[i]);
    }
    return limit >= (v - l - n + r) * m;
}

int main() {
    cin >> n >> m >> v >> p;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << n - meguru_BinarySearch<lint>(n - 1, -1, check) << endl;
}
