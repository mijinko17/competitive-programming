#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int simu(string s) {
    if (s.size() == 1) {
        return s[0] - '0';
    } else {
        int front = s[0] - '0', back = s[1] - '0';
        string t = to_string(front + back);
        return t + s;
    }
}

int main() {
}
