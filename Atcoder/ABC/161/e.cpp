#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    s = 'x' + s + 'x';
    // front[i].first:その日までに働ける日数　.second:次働ける日
    vector<pair<int, int>> front(n + 2);
    front[0] = {0, 1};
    int num = 0;
    int rest = 0;
    for (int i = 1; i <= n; i++) {
        rest--;
        if (rest < 0 && s[i] == 'o') {
            num++;
            front[i] = {num, i + c + 1};
            rest = c;
        } else {
            front[i] = front[i - 1];
        }
    }
    // back[i]:i日めから働ける最大日数
    vector<int> back(n + 2);
    back[n + 1] = 0;
    rest = 0;
    num = 0;
    for (int i = n; i >= 1; i--) {
        rest--;
        if (rest < 0 && s[i] == 'o') {
            num++;
            back[i] = num;
            rest = c;
        } else {
            back[i] = back[i + 1];
        }
    }
    // i日目を抜く
    for (int i = 1; i <= n; i++) {
        int work_boundary = max(i + 1, front[i - 1].second);
        int work = front[i - 1].first + (work_boundary <= n + 1 ? back[work_boundary] : 0);
        if (work < k) {
            cout << i << endl;
        }
    }
}
