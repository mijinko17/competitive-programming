#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string s;
int q;

int main() {
    cin >> s >> q;
    bool isReg = true;
    int num_rev = 0;
    string front = "", back = "";
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            isReg = !isReg;
            num_rev++;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (isReg) {
                if (f == 1) {
                    front.push_back(c);
                } else {
                    back.push_back(c);
                }
            } else {
                if (f == 2) {
                    front.push_back(c);
                } else {
                    back.push_back(c);
                }
            }
        }
    }
    if (num_rev % 2 == 0) {
        reverse(front.begin(), front.end());
        cout << front << s << back << endl;
    } else {
        reverse(back.begin(), back.end());
        reverse(s.begin(), s.end());
        cout << back << s << front << endl;
    }
}
