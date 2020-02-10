#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<string> list;
    int now = 0;
    int from;
    bool flag = false;
    while (now < n) {
        if (s[now] - 'a' < 0) {
            if (!flag) {
                flag = true;
                from = now;
            } else {
                string temp = s.substr(from, now - from + 1);
                temp[0] += 32;
                temp[temp.length() - 1] += 32;
                list.push_back(temp);
                flag = false;
            }
        }
        now++;
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++) {
        list[i][0] -= 32;
        list[i][list[i].length() - 1] -= 32;
        cout << list[i];
    }
    cout << endl;
}
