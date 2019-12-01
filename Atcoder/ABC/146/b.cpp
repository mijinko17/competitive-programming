#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
typedef long long int lint;
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    for (int i = 0; i < s.size(); i++) {
        s[i]='A'+(s[i]-'A'+n)%26;
    }
    cout<<s<<endl;
}
