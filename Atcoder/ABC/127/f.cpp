#include <bits/stdc++.h>
typedef long long llong;
using namespace std;

int q;

int main() {
    cin >> q;
    llong b, x;
    cin >> x >> x >> b;
    priority_queue<llong> small;
    priority_queue<llong, vector<llong>, greater<llong>> large;
    small.push(x);
    llong sum_small = x, sum_large = 0;
    for (int z = 1; z < q; z++) {
        int type;
        cin >> type;
        if (type == 1) {
            int ta, tb;
            cin >> ta >> tb;
            b += tb;
            if (ta < small.top()) {
                sum_small += ta;
                small.push(ta);
                if (small.size() > large.size() + 1) {
                    sum_large += small.top();
                    sum_small -= small.top();
                    large.push(small.top());
                    small.pop();
                }
            } else {
                sum_large += ta;
                large.push(ta);
                if (small.size() < large.size()) {
                    sum_small += large.top();
                    sum_large -= large.top();
                    small.push(large.top());
                    large.pop();
                }
            }
        } else {
            llong ans = 0;
            ans += (llong)small.top() * (llong)small.size() - sum_small;
            ans += sum_large - (llong)small.top() * (llong)large.size();
            ans += b;
            cout << small.top() << " " << ans << endl;
        }
    }
}
