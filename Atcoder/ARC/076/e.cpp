#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int r, c, n;
vector<pair<int, int>> f, b;

bool isBoundary(int p, int q) {
    return p == 0 || p == r || q == 0 || q == c;
}

bool isBothBoundary(int p1, int q1, int p2, int q2) {
    return isBoundary(p1, q1) && isBoundary(p2, q2);
}

int coordinate_trans(int p, int q) {
    if (p == 0) {
        return q;
    } else if (q == c) {
        return c + p;
    } else if (p == r) {
        return c + r + c - q;
    } else {
        return c + r + c + r - p;
    }
}

int main() {
    cin >> r >> c >> n;
    f.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i].first >> f[i].second >> b[i].first >> b[i].second;
    }
    vector<pair<int, int>> separator;
    for (int i = 0; i < n; i++) {
        if (isBothBoundary(f[i].first, f[i].second, b[i].first, b[i].second)) {
            separator.push_back({coordinate_trans(f[i].first, f[i].second), i});
            separator.push_back({coordinate_trans(b[i].first, b[i].second), i});
        }
    }
    sort(separator.begin(), separator.end());
    int m = separator.size();
    int mid = -1;
    for (int i = 0; i < m - 1; i++) {
        if (separator[i].second == separator[i + 1].second) {
            mid = i;
            break;
        }
    }
    if (mid == -1) {
        cout << "NO" << endl;
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < m / 2; i++) {
        int s = (mid - i + m) % m;
        int g = (mid + 1 + i) % m;
        if (separator[s].second != separator[g].second) {
            flag = false;
        }
    }
    string ans = flag ? "YES" : "NO";
    cout << ans << endl;
}
