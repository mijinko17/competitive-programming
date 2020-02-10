#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lint ans = 0;
    for (int i = 0; i < n; i++) {
        lint front = 0, back = 0;
        //前
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                front++;
            }
        }
        //後ろ
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                back++;
            }
        }
        ans += front * back;
    }
    cout << ans << endl;
}
