#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct task {
    int index;
    int start, end;
};

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        cout << "Case #" << Z + 1 << ": ";
        int n;
        cin >> n;
        vector<task> se(n);
        for (int i = 0; i < n; i++) {
            se[i].index = i;
            cin >> se[i].start >> se[i].end;
        }
        sort(se.begin(), se.end(), [](const task a, const task b) { return a.start < b.start; });
        int c_end = -1, j_end = -1;
        bool isPossible = true;
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            if (c_end < j_end) {
                if (se[i].start < c_end) {
                    isPossible = false;
                    break;
                } else {
                    c_end = se[i].end;
                    ans[se[i].index] = 'C';
                }
            } else {
                if (se[i].start < j_end) {
                    isPossible = false;
                    break;
                } else {
                    j_end = se[i].end;
                    ans[se[i].index] = 'J';
                }
            }
        }
        cout << (isPossible ? ans : "IMPOSSIBLE") << endl;
    }
    return 0;
}
