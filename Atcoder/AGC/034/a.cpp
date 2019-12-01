#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

void yes() {
    cout << "Yes" << endl;
}

void no() {
    cout << "No" << endl;
}

int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--;
    if (b < c && c < d) {  // a,b,c,dの順の場合
        for (int i = a; i < d; i++) {
            if (s[i] == '#' && s[i + 1] == '#') {
                no();
                return 0;
            }
        }
    } else if (c < b) {  // a,c,b,dの順の場合
        for (int i = a; i < c; i++) {
            if (s[i] == '#' && s[i + 1] == '#') {
                no();
                return 0;
            }
        }
        for (int i = b; i < d; i++) {
            if (s[i] == '#' && s[i + 1] == '#') {
                no();
                return 0;
            }
        }
    } else {  // a,b,d,cの順の場合
        //追い越さないといけない
        //内側のやつがゴールできるか
        for (int i = max(a, b); i < min(c, d); i++) {
            if (s[i] == '#' && s[i + 1] == '#') {
                no();
                return 0;
            }
        }
        //外側の人がゴールできるか
        bool flag = false;
        //三連続で石のない場所があるか
        for (int i = max(a, b); i <= min(c, d); i++) {
            if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
                //追い越すところに石を置いてしまう
                s[i] = '#';
                flag = true;
                break;
            }
        }
        if (!flag) {
            no();
            return 0;
        }
        for (int i = min(a, b); i < max(c, d); i++) {
            if (s[i] == '#' && s[i + 1] == '#') {
                no();
                return 0;
            }
        }
    }
    yes();
    return 0;
}
