#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

// ただの辺
struct edge {
    int to;
    long long cost;
    // 引数一つの時は距離1
    edge(int t, long long c = 1) : to(t), cost(c) {}
};

int l;
vector<vector<edge>> g;

//二進数の桁数
int width(int x) {
    int res = 0;
    while (x) {
        x /= 2;
        res++;
    }
    return res;
}

bool ispow_2(int x) {
    return x == (1 << (width(x) - 1));
}

int main() {
    cin >> l;
    int num_edge = 0;
    int w = width(l);
    if (ispow_2(l)) {
        g.resize(w);
        for (int i = 0; i < w - 1; i++) {
            g[i].push_back(edge(i + 1, 0));
            g[i].push_back(edge(i + 1, 1 << (w - i - 2)));
            num_edge += 2;
        }
    } else {
        l--;
        g.resize(w);
        for (int i = 0; i < w - 1; i++) {
            g[i].push_back(edge(i + 1, 0));
            g[i].push_back(edge(i + 1, 1 << (w - i - 2)));
            num_edge += 2;
        }
        bitset<20> b(l + 1);
        int now = 1 << (w - 1);
        for (int i = w - 2; i >= 0; i--) {
            if (b[i]) {
                g[0].push_back(edge(w - i - 1, now));
                num_edge++;
                now += 1 << i;
            }
        }
    }

    cout << g.size() << " " << num_edge << endl;
    for (int i = 0; i < g.size(); i++) {
        for (auto e : g[i]) {
            cout << i + 1 << " " << e.to + 1 << " " << e.cost << endl;
        }
    }
}
