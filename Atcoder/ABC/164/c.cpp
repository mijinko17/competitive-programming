#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    cout << st.size() << endl;
}
