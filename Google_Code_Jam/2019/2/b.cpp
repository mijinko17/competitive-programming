#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int Z = 0; Z < T; Z++) {
        int day;
        int trash;
        int target;
        int b = 62;
        vector<int> num(10, 0);
        vector<queue<int>> unused(10);
        priority_queue<pair<int, int>> pq;
        for (int i = 1; i <= 100; i++) {
            cin >> day;
            if (i <= b) {
                cout << i % 10 + 11 << ' ' << 1 << endl;
                fflush(stdout);
            } else if (i <= b + 10) {
                cout << i - b << ' ' << 0 << endl;
                fflush(stdout);
                cin >> num[i - b - 1];
                pq.push({-num[i - b - 1], i - b - 1});
                for (int j = 0; j < num[i - b - 1]; j++) {
                    cin >> trash;
                    for (int k = 0; k < 10; k++) {
                        if (k == i - b - 1) continue;
                        unused[k].push(trash);
                    }
                }
                if (i == b + 10) {
                    pq.pop();
                }
            } else if (i <= 90) {
                auto now = pq.top();
                pq.pop();
                int t = now.second;
                int s = 100;
                if (!unused[t].empty()) {
                    s = unused[t].front();
                    unused[t].pop();
                }
                cout << t + 1 << ' ' << s << endl;
                fflush(stdout);
                now.first--;
                pq.push(now);
            } else {
                cout << i - 90 << ' ' << 100 << endl;
                fflush(stdout);
            }
        }
    }
    return 0;
}
