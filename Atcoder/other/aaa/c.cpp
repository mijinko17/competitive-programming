#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h + 1);
    vector<int> num_s(h + 1);
    vector<pair<int, int>> layer;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') num_s[i]++;
        }
    }
    num_s[h] = 1;
    bool flag = false;
    int front = 0;
    queue<pair<int, int>> task;
    for (int i = 0; i <= h; i++) {
        if (num_s[i] != 0) {
            if (flag) {
                task.push(make_pair(front, i));
                front = i;
            } else {
                flag = true;
            }
        }
    }
    vector<vector<int>> ans(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        s[i] = s[i] + '#';
    }
    int n = 1;
    while (!task.empty()) {
        bool flag2 = false;
        int front2 = 0;
        auto now = task.front();
        task.pop();
        for (int i = 0; i <= w; i++) {
            int temp = 0;
            for (int j = now.first; j < now.second; j++) {
                if (s[j][i] == '#') {
                    temp++;
                }
            }
            if (temp > 0) {
                if (flag2) {
                    for (int k = now.first; k < now.second; k++) {
                        for (int l = front2; l < i; l++) {
                            ans[k][l] = n;
                        }
                    }
                    n++;
                    front2 = i;
                } else {
                    flag2 = true;
                }
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
