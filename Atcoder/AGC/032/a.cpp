#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> b;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    stack<int> ans;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        // b[i]=iなるiで最大のやつを見つけたい(そのイテラをtargetとする)
        auto target = b.end();
        int now = 1;
        for (auto itr = b.begin(); itr != b.end(); itr++) {
            if (*itr == now) {
                target = itr;
            }
            now++;
        }
        if (target != b.end()) {
            ans.push(*target);
            b.erase(target);
        } else {
            flag = false;
            break;
        }
    }
    if (flag) {
        while (!ans.empty()) {
            cout << ans.top() << endl;
            ans.pop();
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
