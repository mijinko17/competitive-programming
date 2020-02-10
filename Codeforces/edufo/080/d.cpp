#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, m;
vector<vector<lint>> a;

bool check(lint k) {
    unordered_set<bitset<8>> ls;
    for (int i = 0; i < n; i++) {
        bitset<8> bit(0);
        for (int j = 0; j < m; j++) {
            bit[j] = a[i][j] >= k;
        }
        ls.insert(bit);
    }
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if ((i | j) == (1 << m) - 1 && ls.count(bitset<8>(i)) &&
                ls.count(bitset<8>(j))) {
                return true;
            }
        }
    }
    return false;
}

// めぐる式二分探索
template <typename T>
T meguru_BinarySearch(T ok, T no, function<bool(T)> isValid, T diff = 1) {
    while (abs(ok - no) > diff) {
        T mid = (ok + no) / 2;
        if (isValid(mid))
            ok = mid;
        else
            no = mid;
    }
    return ok;
}

int main() {
    cin >> n >> m;
    a.assign(n, vector<lint>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    lint k = meguru_BinarySearch<lint>(0, INT_MAX, check);
    unordered_set<bitset<8>> ls;
    unordered_map<bitset<8>, int> index;
    for (int i = 0; i < n; i++) {
        bitset<8> b;
        for (int j = 0; j < m; j++) {
            b[j] = a[i][j] >= k;
        }
        ls.insert(b);
        index[b] = i;
    }
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if ((i | j) == (1 << m) - 1 && ls.count(bitset<8>(i)) &&
                ls.count(bitset<8>(j))) {
                cout << index[bitset<8>(i)] + 1 << " "
                     << index[bitset<8>(j)] + 1 << endl;
                return 0;
            }
        }
    }
}
