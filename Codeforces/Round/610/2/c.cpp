#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
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
    lint &operator[](const int k) {
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
    int m;
    cin >> m;
    while (m--) {
        lint n, tl, a, b;
        cin >> n >> tl >> a >> b;
        lint num_a = 0, num_b = 0;
        vector<lint> type(n), t(n);
        for (int i = 0; i < n; i++) {
            cin >> type[i];
            if (type[i] == 0)
                num_a++;
            else
                num_b++;
        }
        set<lint> st;
        st.insert(tl + 1);
        for (int i = 0; i < n; i++) {
            cin >> t[i];
            st.insert(t[i]);
        }
        // fi:time,se:type
        vector<pair<lint, lint>> s(n);
        for (int i = 0; i < n; i++) {
            s[i].first = t[i];
            s[i].second = type[i];
        }
        sort(s.begin(), s.end());
        cumulative_sum count_a(n), count_b(n);
        for (int i = 0; i < n; i++) {
            if (s[i].second == 0)
                count_a[i]++;
            else
                count_b[i]++;
        }
        count_a.build();
        count_b.build();
        lint ans = 0;
        //[0,e)の問題を解く
        for (auto e : st) {
            lint index =
                lower_bound(s.begin(), s.end(), make_pair(e, -1LL)) - s.begin();
            lint solve_a = count_a.query(0, index);
            lint solve_b = count_b.query(0, index);
            lint rem = e - 1 - solve_a * a - solve_b * b;
            //残り時間でいっぱい問題解く
            if (rem >= 0) {
                lint add_a = min(rem / a, num_a - solve_a);
                solve_a += add_a;
                rem -= add_a * a;
                lint add_b = min(rem / b, num_b - solve_b);
                solve_b += add_b;
                chmax(ans, solve_a + solve_b);
            }
        }
        cout << ans << endl;
    }
}
