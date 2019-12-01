#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

pair<int, int> solve(int a, int b) {
    if (a > b) {
        auto temp = solve(b, a);
        return make_pair(temp.second, temp.first);
    } else {
        if (a == 0) {
            return make_pair(0, 1);
        } else {
            auto temp = solve(a, b % a);
            int v = temp.first, w = temp.second;
            return make_pair(v - w * (b / a), w);
        }
    }
}

int main() {
    auto temp = solve(6, 1e+9 + 7);
    cout << temp.first << " " << temp.second << endl;
}
