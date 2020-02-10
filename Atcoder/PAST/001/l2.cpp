#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

//素集合データ構造
// ref:https://ei1333.github.io/luzhiled/snippets/structure/union-find.html
struct union_find {
    // parent[v]==w(>=0):vの親はw
    // parent[v]==k(<0):vは根&&vの属するグループの要素数は-k
    vector<long long int> parent;
    //コンストラクタ
    union_find(long long int n) {
        parent.assign(n, -1);
    }
    // vの根を求める
    //求めると同時に親を根に置き換える(木の圧縮)
    long long int root(long long int v) {
        if (parent[v] < 0) {
            return v;
        } else {
            parent[v] = root(parent[v]);
            return parent[v];
        }
    }
    // vが属するグループの要素数を求める
    long long int size(long long int v) {
        return -parent[root(v)];
    }
    // vとwを繋げる
    void unite(long long int v, long long int w) {
        v = root(v);
        w = root(w);
        if (v == w) return;
        if (parent[v] < parent[w]) swap(v, w);
        parent[w] += parent[v];
        parent[v] = w;
    }
    // vとwが同値か判定
    bool isSame(long long int v, long long int w) {
        return root(v) == root(w);
    }
};

int n, m;
vector<vector<double>> d;
priority_queue<pair<double, pair<int, int>>,
               vector<pair<double, pair<int, int>>>,
               greater<pair<double, pair<int, int>>>>
    pq;

lint num_stand(bitset<35> b) {
    lint res = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) {
            res++;
        }
    }
    return res;
}

double minTree(lint k) {
    bitset<35> bit((1LL << n) - 1 + (k << n));
    int rem = num_stand(bit) - 1;
    auto p = pq;
    double res = 0;
    union_find uf(n + m);
    int count = 0;
    while (rem && count < 1000) {
        auto now = p.top();
        p.pop();
        int u = now.second.first, v = now.second.second;
        if (bit[u] == 0 || bit[v] == 0) {
            continue;
        }
        if (!uf.isSame(u, v)) {
            uf.unite(u, v);
            res += now.first;
            rem--;
        }
        count++;
    }
    return res;
}

double dist(int p, int q, int r, int s) {
    double x = abs(p - r), y = abs(q - s);
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n >> m;
    vector<int> x(n + m), y(n + m), c(n + m);
    for (int i = 0; i < n + m; i++) {
        cin >> x[i] >> y[i] >> c[i];
    }
    d.assign(n + m, vector<double>(n + m, 0));
    for (int i = 0; i < n + m; i++) {
        for (int j = i + 1; j < n + m; j++) {
            double cost = dist(x[i], y[i], x[j], y[j]);
            if (c[i] != c[j]) {
                cost *= 10;
            }
            d[i][j] = cost;
            d[j][i] = cost;
        }
    }
    for (int i = 0; i < n + m; i++) {
        for (int j = i + 1; j < n + m; j++) {
            pq.push({d[i][j], {i, j}});
        }
    }
    double ans = LLONG_MAX;
    for (int i = 0; i < (1 << m); i++) {
        ans = min(ans, minTree((lint)i));
    }
    cout << setprecision(9) << ans << endl;
}
