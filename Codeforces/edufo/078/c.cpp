#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            cin >> left[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> right[i];
        }
        reverse(right.begin(), right.end());
        // diff_left[i]:いちごーブルーベリー=iなるようにする最小の左の食べ方
        vector<int> diff_left_p(n + 1, -1), diff_right_p(n + 1, -1);
        vector<int> diff_left_m(n + 1, -1), diff_right_m(n + 1, -1);
        diff_left_m[0] = 0;
        diff_left_p[0] = 0;
        diff_right_m[0] = 0;
        diff_right_p[0] = 0;
        int s = 0, b = 0;

        for (int i = 0; i < n; i++) {
            if (left[i] == 1) {
                s++;
            } else {
                b++;
            }
            if (s - b >= 0) {
                chmax(diff_left_p[s - b], i + 1);
            }
            if (s - b <= 0) {
                chmax(diff_left_m[b - s], i + 1);
            }
        }
        s = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (right[i] == 1) {
                s++;
            } else {
                b++;
            }
            if (s - b >= 0) {
                chmax(diff_right_p[s - b], i + 1);
            }
            if (s - b <= 0) {
                chmax(diff_right_m[b - s], i + 1);
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            if (diff_left_p[i] != -1 && diff_right_m[i] != -1) {
                chmin(ans, 2 * n - diff_left_p[i] - diff_right_m[i]);
            }
        }
        for (int i = 0; i <= n; i++) {
            if (diff_left_m[i] != -1 && diff_right_p[i] != -1) {
                chmin(ans, 2 * n - diff_left_m[i] - diff_right_p[i]);
            }
        }
        cout << ans << endl;
    }
}
