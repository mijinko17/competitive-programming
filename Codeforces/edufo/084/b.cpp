#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> vec(n);
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            vec[i].resize(num);
            for (int j = 0; j < num; j++) {
                cin >> vec[i][j];
                vec[i][j]--;
            }
        }
        vector<bool> prince(n, false);
        int max_princess = INT_MIN;
        for (int i = 0; i < n; i++) {
            bool marry = false;
            for (int j = 0; j < vec[i].size(); j++) {
                if (!prince[vec[i][j]]) {
                    prince[vec[i][j]] = true;
                    marry = true;
                    break;
                }
            }
            if (!marry) {
                max_princess = i;
            }
        }
        if (max_princess == INT_MIN) {
            cout << "OPTIMAL" << endl;
        } else {
            cout << "IMPROVE" << endl << max_princess + 1 << " ";
            for (int i = 0; i < n; i++) {
                if (!prince[i]) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}
