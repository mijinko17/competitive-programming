#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    vector<int> a = {1, 2, 7, 7, 9, 20};
    while (1) {
        for (auto e : a) {
            cout << e << " ";
        }
        cout << endl;
        auto m = max_element(a.begin(), a.end());
        cout << (*m) - (*min_element(a.begin(), a.end())) << endl;
        if (*m < a.size()) break;
        (*m) -= (int)(a.size() + 1);
        for (auto &e : a) {
            e++;
        }
    }
}
