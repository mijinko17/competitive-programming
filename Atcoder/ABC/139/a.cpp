#include <bits/stdc++.h>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int ans=0;
	if (s[0]==t[0]) {
		ans++;
	}
	if (s[1]==t[1]) {
		ans++;
	}
	if (s[2]==t[2]) {
		ans++;
	}
	cout<<ans<<endl;
}
