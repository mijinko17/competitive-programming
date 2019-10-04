#include <bits/stdc++.h>
using namespace std;

// n:次に使う竹
int dfs(int n, vector<int> l, vector<int> take, vector<int> pretake, int mp) {
    if (n == l.size()) {
        int res = mp;
        for (int i = 0; i < 3; i++) {
            if (pretake[i] == 0) {
                return 1e+9;
            }
        }
        for (int i = 0; i < 3; i++) {
            res += abs(take[i] - pretake[i]);
        }
        return res;
    } else {
        vector<int> cand(4);
        for (int i = 0; i < 3; i++) {
            int tmp = mp;
            vector<int> tp = pretake;
            if (tp[i] > 0) tmp += 10;
            tp[i] += l[n];
            cand[i] = dfs(n + 1, l, take, tp, tmp);
        }
        return *min_element(cand.begin(), cand.end());
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> take(3);
    for (int i = 0; i < 3; i++) {
        cin >> take[i];
    }
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> pretake = {0, 0, 0};

    cout << dfs(0, l, take, pretake, 0) << endl;
}
