#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

string s;
int k;

int main() {
    cin >> s >> k;
    int n = s.length();
    vector<vector<lint>> dpj(k, vector<lint>(n));
    vector<vector<lint>> dpe(k, vector<lint>(n));
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            for (int j = 0; j < k; j++) {
                dpj[j + 1][i + 1] = dpj[j][i];
            }
        }
    }
}
