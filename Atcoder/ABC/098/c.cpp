#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int left_w = 0, right_e = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'E') right_e++;
    }
    s = s + 'Z';
    int ans = INT_MAX;
    // i:リーダーの場所
    for (int i = 0; i < n; i++) {
        ans = min(ans, left_w + right_e);
        if (s[i] == 'W') left_w++;
        if (s[i + 1] == 'E') right_e--;
    }
    cout << ans << endl;
}
