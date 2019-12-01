#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length() + 1;
    vector<int> test(n);
    test[0] = 0;
    auto c = [](const pair<int, int> x, const pair<int, int> y) {
        return x.first > y.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(c)> pq(c);
    pq.push({test[0], 0});
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '>') {
            test[i] = test[i - 1] - 1;
        } else {
            test[i] = test[i - 1] + 1;
        }
        pq.push({test[i], i});
    }
    vector<int> ans(n, -1);
    while (!pq.empty()) {
        int index = pq.top().second;
        pq.pop();
        if (ans[index] >= 0) {
            continue;
        }
        ans[index] = 0;
        int left = index - 1, right = index;
        while (left >= 0 && s[left] == '>' && ans[left] < 0) {
            ans[left] = ans[left + 1] + 1;
            left--;
        }
        while (right < n - 1 && s[right] == '<' && ans[right + 1] < 0) {
            ans[right + 1] = ans[right] + 1;
            right++;
        }
    }
    lint sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ans[i];
    }
    cout << sum << endl;
}
