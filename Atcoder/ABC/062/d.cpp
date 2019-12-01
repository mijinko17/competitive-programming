#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(3 * n);
    priority_queue<int, vector<int>, greater<int>> a_front;
    priority_queue<int> a_back;
    for (int i = 0; i < 3 * n; i++) {
        cin >> a[i];
        if (i < n) {
            a_front.push(a[i]);
        }
        if (i >= 2 * n) {
            a_back.push(a[i]);
        }
    }
    //区間を[0,n+i),[n+i,3*n)と切った時の和
    vector<lint> front_sum(n + 1, 0), back_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        front_sum[0] += a[i];
    }
    for (int i = 0; i < n; i++) {
        back_sum[n] += a[2 * n + i];
    }
    // front_sumを構築
    for (int i = 0; i < n; i++) {
        a_front.push(a[n + i]);
        front_sum[i + 1] = front_sum[i] + a[n + i] - a_front.top();
        a_front.pop();
    }
    // back_sumを構築
    for (int i = 0; i < n; i++) {
        a_back.push(a[2 * n - 1 - i]);
        back_sum[n - 1 - i] = back_sum[n - i] + a[2 * n - 1 - i] - a_back.top();
        a_back.pop();
    }
    //最大のやつを探す
    lint ans = LLONG_MIN;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, front_sum[i] - back_sum[i]);
    }
    cout << ans << endl;
}
