#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

void yes() {
    cout << "Yes" << endl;
}
void no() {
    cout << "No" << endl;
}

int main() {
    int n;
    cin >> n;
    // k*(k-1)=2*nとかけるかチェック
    int k = 1;
    while (true) {
        if (k * (k - 1) == 2 * n) break;
        if (k * (k - 1) > 2 * n) {
            no();
            return 0;
        }
        k++;
    }
    //集合を作る
    vector<vector<int>> s(k);
    int now = 1;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            s[i].push_back(now);
            s[j].push_back(now);
            now++;
        }
    }
    //答える
    yes();
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << k - 1 << " ";
        for (int j = 0; j < k - 1; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }
}
