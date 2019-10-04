#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(98);
    for (int i = 0; i < 98; i++) {
        cin >> a[i];
    }
    cout << "{";
    for (int i = 0; i < 98; i++) {
        cout << a[i];
        if (i < 97) {
            cout << ",";
        }
    }
    cout << "}" << endl;
}
