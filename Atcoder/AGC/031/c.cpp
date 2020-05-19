#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

const int l = 17;

vector<bitset<l>> any2any(bitset<l> start, bitset<l> goal, int dim) {
    if (dim == 1) {
        if (start == 0) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (start != bitset<l>(0)) {
        auto res = any2any(0, goal ^ start, dim);
        for (auto &e : res) {
            e ^= start;
        }
        return res;
    }
    if (goal[dim - 1] == 0) {
        int replace = -1;
        for (int i = 0; i < l; i++) {
            if (goal[i] == 1) {
                replace = i;
                break;
            }
        }
        goal[dim - 1] = 1, goal[replace] = 0;
        auto res = any2any(0, goal, dim);
        for (auto &e : res) {
            int a = e[dim - 1], b = e[replace];
            e[dim - 1] = b, e[replace] = a;
        }
        return res;
    }
    goal[dim - 1] = 0;
    auto y = goal ^ bitset<l>(1);
    auto half_0 = any2any(0, y, dim - 1);
    auto half_1 = any2any(y, goal, dim - 1);
    for (auto e : half_1) {
        e[dim - 1] = 1;
        half_0.push_back(e);
    }
    return half_0;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    bitset<17> x(a), y(b);
    if (x.count() % 2 == y.count() % 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        auto res = any2any(x, y, n);
        for (auto e : res) {
            cout << e.to_ulong() << endl;
        }
    }
    return 0;
}
