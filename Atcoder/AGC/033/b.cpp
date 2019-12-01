#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int h, w, n, sr, sc;
    string s, t;
    cin >> h >> w >> n >> sr >> sc >> s >> t;
    //縦
    int top = 0, bottom = h + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 'U') {
            bottom = min(bottom + 1, h + 1);
        } else if (t[i] == 'D') {
            top = max(top - 1, 0);
        }
        if (s[i] == 'U') {
            top++;
        } else if (s[i] == 'D') {
            bottom--;
        }
        if (top + 1 == bottom) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sr <= top || sr >= bottom) {
        cout << "NO" << endl;
        return 0;
    }
    //横
    int left = 0, right = w + 1;
    for (int i = n - 1; i >= 0; i--) {
        if (t[i] == 'L') {
            right = min(right + 1, w + 1);
        } else if (t[i] == 'R') {
            left = max(left - 1, 0);
        }
        if (s[i] == 'L') {
            left++;
        } else if (s[i] == 'R') {
            right--;
        }
        if (left + 1 == right) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (sc <= left || sc >= right) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
}
