#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

bool head_match(string a, string b) {
    if (a.length() > b.length()) {
        swap(a, b);
    }
    return a == b.substr(0, a.length());
}
bool tail_match(string a, string b) {
    if (a.length() > b.length()) {
        swap(a, b);
    }
    return a == b.substr(b.length() - a.length(), a.length());
}

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        bool possible = true;
        //頭と尻がいっちしてるか見る
        string head = "";
        string hip = "";
        string inner = "";
        for (int i = 0; i < n; i++) {
            int head_len = 0;
            for (int j = 0; j < s[i].length(); j++) {
                if (s[i][j] != '*') {
                    head_len++;
                } else {
                    break;
                }
            }
            string now_head = s[i].substr(0, head_len);
            if (head_match(now_head, head)) {
                if (now_head.length() > head.length()) {
                    head = now_head;
                }
            } else {
                possible = false;
                break;
            }
            int hip_len = 0;
            for (int j = s[i].length() - 1; j >= 0; j--) {
                if (s[i][j] != '*') {
                    hip_len++;
                } else {
                    break;
                }
            }
            string now_hip = s[i].substr(s[i].length() - hip_len, hip_len);
            if (tail_match(now_hip, hip)) {
                if (now_hip.length() > hip.length()) {
                    hip = now_hip;
                }
            } else {
                possible = false;
                break;
            }
            for (int j = head_len; j < s[i].length() - hip_len; j++) {
                if (s[i][j] != '*') {
                    inner.push_back(s[i][j]);
                }
            }
        }
        if (possible) {
            cout << head << inner << hip << endl;
        } else {
            cout << "*" << endl;
        }
    }
    return 0;
}
