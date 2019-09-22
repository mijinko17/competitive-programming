#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int flag=0;
	for (int i = 0; i < s.length(); i++) {
		if (i%2==0) {
			if (s[i]=='L') {
				flag=1;
			}
		}else {
			if (s[i]=='R') {
				flag=1;
			}
		}
	}
	if (flag==1) {
		cout<<"No"<<endl;
	}else {
		cout<<"Yes"<<endl;
	}
}
