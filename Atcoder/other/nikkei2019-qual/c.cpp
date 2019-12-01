#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    lint diff = 0;
    priority_queue<lint> pq;
    for (int i = 0; i < n; i++) {
        lint a, b;
        cin >> a >> b;
        pq.push(a + b);
        diff += a;
    }
    // turn=0なら高橋くんの番
    int turn = 0;
    while (!pq.empty()) {
        lint now = pq.top();
        pq.pop();
        if (turn == 1) {
            diff -= now;
        }
        turn = 1 - turn;
    }
    cout << diff << endl;
}
