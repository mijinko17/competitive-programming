#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp;
    vector<int> color(1);
    cin >> color[0];
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (color[color.size() - 1] != temp) {
            color.push_back(temp);
        }
    }
    // pc[i]:今まで見てきたiを塗る時の
    unordered_map<int, lint> pc;
    // before:今調べてるとこまでのパターン総数
    lint before = 1;
}
