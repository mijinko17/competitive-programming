#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    // train[i]:左端が街i以東であるような電車のリスト、入ってるのは終点の街
    vector<vector<int>> train(n);
    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        for (int j = 0; j < l; j++) {
            train[j].push_back(r - 1);
        }
    }
    vector<int> x(q), y(q);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    //二分探索用にtrain[i]をソート
    for (int i = 0; i < n; i++) {
        sort(all(train[i]));
    }
    for (int i = 0; i < q; i++) {
        auto itr = upper_bound(all(train[x[i]]), y[i]);
        cout << itr - train[x[i]].begin() << endl;
    }
    return 0;
}
