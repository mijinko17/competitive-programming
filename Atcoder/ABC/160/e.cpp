#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint x, y, a, b, c;
vector<lint> p, q, r;
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
    lint& operator[](const int k) {
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
    cin >> x >> y >> a >> b >> c;
    p.resize(a), q.resize(b), r.resize(c);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < c; i++) {
        cin >> r[i];
    }
    sort(p.begin(), p.end(), greater<lint>());
    sort(q.begin(), q.end(), greater<lint>());
    sort(r.begin(), r.end(), greater<lint>());
    cumulative_sum cum_p(a), cum_q(b), cum_r(c);
    for (int i = 0; i < a; i++) {
        cum_p[i] = p[i];
    }
    for (int i = 0; i < b; i++) {
        cum_q[i] = q[i];
    }
    for (int i = 0; i < c; i++) {
        cum_r[i] = r[i];
    }
    cum_p.build(), cum_q.build(), cum_r.build();
    priority_queue<lint> green;
    lint green_sum = cum_q.query(0, y);
    for (int i = 0; i < y; i++) {
        green.push(q[i]);
    }
    lint ans = 0;
    int k = max(0LL, x - c);
    //赤をi個食べる
    for (int i = k; i < x; i++) {
        lint cand = cum_p.query(0, i);
    }
}
