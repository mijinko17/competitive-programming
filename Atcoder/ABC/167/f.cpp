#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
vector<pair<string, pair<int, int>>> a, b, c, d;

template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

pair<int, int> min_res_depth(string s) {
    int r_min = 0, r_res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            r_res++;

        } else {
            r_res--;
        }
        chmin(r_min, r_res);
    }
    return make_pair(r_min, r_res);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto depth = min_res_depth(s);
        if (depth.first == 0) {
            a.push_back({s, depth});
        } else if (depth.second >= 0) {
            d.push_back({s, depth});
        } else if (depth.first == depth.second) {
            b.push_back({s, depth});
        } else {
            c.push_back({s, depth});
        }
    }
    sort(c.begin(), c.end(), [](pair<string, pair<int, int>> x, pair<string, pair<int, int>> y) {
        return x.second.first < y.second.first;
    });
    sort(d.begin(), d.end(), [](pair<string, pair<int, int>> x, pair<string, pair<int, int>> y) {
        return x.second.first > y.second.first;
    });
    if (b.empty() && c.empty() && d.empty()) {
        for (auto e : a) {
            if (e.second.second != 0) {
                cout << "No" << endl;
                return 0;
            }
            cout << "Yes" << endl;
            return 0;
        }
    }
    bool has_left = false, has_right = false;
    for (auto e : a) {
        if (e.first.front() == '(') {
            has_left = true;
            break;
        }
    }
    for (auto e : b) {
        if (e.first.back() == ')') {
            has_right = true;
            break;
        }
    }
    if (has_right && has_right) {
        int now_depth = 0;
        for (auto e : a) {
            if (now_depth + e.second.first < 0) {
                cout << "No" << endl;
                return 0;
            }
            now_depth += e.second.second;
        }
        for (auto e : d) {
            if (now_depth + e.second.first < 0) {
                cout << "No" << endl;
                return 0;
            }
            now_depth += e.second.second;
        }
        for (auto e : c) {
            if (now_depth + e.second.first < 0) {
                cout << "No" << endl;
                return 0;
            }
            now_depth += e.second.second;
        }
        for (auto e : b) {
            if (now_depth + e.second.first < 0) {
                cout << "No" << endl;
                return 0;
            }
            now_depth += e.second.second;
        }
        if (now_depth == 0) {
            cout << "Yes" << endl;

        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
