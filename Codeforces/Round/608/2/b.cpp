#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

char bw(char c) {
    return c == 'B' ? 'W' : 'B';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    //全部黒にできるか
    string sb = s;
    vector<int> ansb;
    for (int i = 0; i < n - 1; i++) {
        if (sb[i] == 'W') {
            ansb.push_back(i + 1);
            sb[i + 1] = bw(sb[i + 1]);
        }
    }
    if (sb[n - 1] == 'B') {
        cout << ansb.size() << endl;
        for (int i = 0; i < ansb.size(); i++) {
            cout << ansb[i] << " ";
        }
        cout << endl;
        return 0;
    }
    //全部白にできるか
    string sw = s;
    vector<int> answ;
    for (int i = 0; i < n - 1; i++) {
        if (sw[i] == 'B') {
            answ.push_back(i + 1);
            sw[i + 1] = bw(sw[i + 1]);
        }
    }
    if (sw[n - 1] == 'W') {
        cout << answ.size() << endl;
        for (int i = 0; i < answ.size(); i++) {
            cout << answ[i] << " ";
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
}
