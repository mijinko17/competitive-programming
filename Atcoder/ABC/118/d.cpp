#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

struct match {
    vector<int> numbers;
    match() {
        numbers.assign(10, 0);
        numbers[0] = -1;
    }
    bool operator>(match m) {
        if (this->numbers[0] != m.numbers[0]) {
            return this->numbers[0] > m.numbers[0];
        }
        for (int i = 9; i >= 1; i--) {
            if (this->numbers[i] != m.numbers[i]) {
                return this->numbers[i] > m.numbers[i];
            }
        }
        return false;
    }
};

int main() {
    vector<int> need = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n, m;
    cin >> n >> m;
    vector<int> usable(m);
    for (int i = 0; i < m; i++) {
        cin >> usable[i];
    }
    // dp[i]:マッチi本使って作れる最強のマッチ組
    vector<match> dp(n + 1, match());
    dp[0].numbers[0] = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + need[usable[i]] > n || dp[j].numbers[0] < 0) {
                continue;
            }
            match temp = dp[j];
            temp.numbers[0]++;
            temp.numbers[usable[i]]++;
            if (temp > dp[j + need[usable[i]]]) {
                dp[j + need[usable[i]]] = temp;
            }
        }
    }
    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < dp[n].numbers[i]; j++) {
            cout << i;
        }
    }
    cout << endl;
}
