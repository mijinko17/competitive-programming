#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int n, k;

int main() {
    cin >> n >> k;
    int bridge = (n - 1) * (n - 2) / 2 - k;
    if (bridge < 0) {
        cout << -1 << endl;
    } else {
        cout << n - 1 + bridge << endl;
        //ウニ部分
        for (int i = 1; i < n; i++) {
            cout << 1 << " " << i + 1 << endl;
        }
        //橋部分
        int count = 0;
        for (int i = 1; i < n && count < bridge; i++) {
            for (int j = i + 1; j < n && count < bridge; j++) {
                cout << i + 1 << " " << j + 1 << endl;
                count++;
            }
        }
    }
}
