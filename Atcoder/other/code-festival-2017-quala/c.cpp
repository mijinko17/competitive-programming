#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

void no() {
    cout << "No" << endl;
}

int main() {
    int h, w;
    cin >> h >> w;
    unordered_map<char, int> count;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            count[c]++;
        }
    }
    if (h % 2 == 0 && w % 2 == 0) {  //両方偶数
        for (auto itr = count.begin(); itr != count.end(); itr++) {
            auto now = *itr;
            if (now.second % 4 != 0) {
                no();
                return 0;
            }
        }
    } else if ((h + w) % 2 == 1) {  //片っぽ奇数
        // h:奇数と思いたい
        if (h % 2 == 0) swap(h, w);
        // a:4n
        int a = 0;
        for (auto itr = count.begin(); itr != count.end(); itr++) {
            auto now = (*itr).second;
            if (now % 2 != 0) {
                no();
                return 0;
            } else if (now % 4 != 0) {
                a++;
            }
        }
        if (a > w / 2) {
            no();
            return 0;
        }
    } else {  //両方奇数
        // a:4n+2,b:奇数
        int a = 0, b = 0;
        for (auto itr = count.begin(); itr != count.end(); itr++) {
            auto now = (*itr).second;
            if (now % 2 != 0) {
                b++;
            } else if (now % 4 != 0) {
                a++;
            }
        }
        if (a > h / 2 + w / 2 || b != 1) {
            no();
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
