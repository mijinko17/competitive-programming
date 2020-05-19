#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint k;

// a^nを計算　O(log n)
long long int powint(long long int a, long long int n) {
    if (n == 0) {
        return 1;
    } else {
        long long int temp = powint(a, n / 2);
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * a;
        }
    }
}

int main() {
    cin >> k;
    //[i][j]:iけた先頭jのルンルン数小さい順
    vector<vector<vector<lint>>> lunlun(11, vector<vector<lint>>(10));
    for (int i = 0; i < 10; i++) {
        lunlun[1][i].push_back(i);
    }
    set<lint> ans;
    // i桁
    for (int i = 2; i <= 10; i++) {
        //先頭j
        for (int j = 0; j < 10; j++) {
            if (j - 1 >= 0) {
                for (auto e : lunlun[i - 1][j - 1]) {
                    lunlun[i][j].push_back(powint(10, i - 1) * j + e);
                }
            }
            for (auto e : lunlun[i - 1][j]) {
                lunlun[i][j].push_back(powint(10, i - 1) * j + e);
            }
            if (j + 1 <= 9) {
                for (auto e : lunlun[i - 1][j + 1]) {
                    lunlun[i][j].push_back(powint(10, i - 1) * j + e);
                }
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (auto e : lunlun[i][j]) {
                ans.insert(e);
                if (ans.size() == k + 1) {
                    cout << e << endl;
                    return 0;
                }
            }
        }
    }
}
