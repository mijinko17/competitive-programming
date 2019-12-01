#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    string s;
    cin >> s;
    //各文字の登場回数をカウント
    unordered_map<char, int> count;
    for (int i = 0; i < s.length(); i++) {
        count[s[i]]++;
    }
    //奇数個しかないものをカウント
    int num_odd = 0;
    for (auto itr = count.begin(); itr != count.end(); itr++) {
        if ((*itr).second % 2 != 0) num_odd++;
    }
    if (num_odd == 0) {
        cout << s.length() << endl;
    } else {
        int num_pair_even = (s.length() - num_odd) / 2;
        cout << (num_pair_even / num_odd) * 2 + 1 << endl;
    }
}
