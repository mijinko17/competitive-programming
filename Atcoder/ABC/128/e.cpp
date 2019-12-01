#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
typedef long long int lint;
using namespace std;

struct event {
    int time;
    // true:スタート、false:終了
    bool kind;
    int place;
    event(int t, bool k, int p) : time(t), kind(k), place(p) {
    }
    event() {
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<event> flow(n * 2);
    for (int i = 0; i < n; i++) {
        int s, t, x;
        cin >> s >> t >> x;
        flow[2 * i] = event(s - x, true, x);
        flow[2 * i + 1] = event(t - x, false, x);
    }
    vector<int> d(q);
    for (int i = 0; i < q; i++) {
        cin >> d[i];
    }
    sort(all(flow),
         [](const event x, const event y) { return x.time < y.time; });
    multiset<int> roadworks;
    int next = 0;
    for (int i = 0; i < q; i++) {
        while (flow[next].time <= d[i] && next < 2 * n) {
            if (flow[next].kind) {
                roadworks.insert(flow[next].place);
            } else {
                roadworks.erase(roadworks.find(flow[next].place));
            }
            next++;
        }
        if (roadworks.size() > 0) {
            cout << *roadworks.begin() << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
