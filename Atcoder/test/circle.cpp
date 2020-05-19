#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

using coord = pair<double, double>;

int n, k;
vector<coord> xy;
vector<double> c;

struct circle {
    coord center;
    double radius;
    circle() {}
    circle(coord _c, double _r) : radius(_r) {
        center = _c;
    }
};

double dist(coord a, coord b) {
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

pair<coord, coord> intersect(circle a, circle b) {
    if (dist(a.center, b.center) > a.radius + b.radius ||
        dist(a.center, b.center) < abs(a.radius - b.radius)) {
        return {{-1, -1}, {-1, -1}};
    }
}

bool isvalid(double m) {
    vector<bitset<60>> adj(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        }
    }
    vector<vector<bitset<60>>> dp(n);
    dp[0].push_back(0);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            for (auto e : dp[j]) {
            }
        }
    }
}

int main() {
    cin >> n >> k;
    xy.resize(n), c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> xy[i].first >> xy[i].second >> c[i];
    }
}
