#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << pq.size() << endl;
        int h;
        cin >> h;
        while (pq.size() != 0) {
            if (pq.top() < h) {
                pq.pop();
            } else {
                break;
            }
        }
        pq.push(h);
    }
}
