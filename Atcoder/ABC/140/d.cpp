#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	int flag=0;
	int ans=0;
	for (int i = 0; i < n-1; i++) {
		if (k>0) {
			if (s[i]!=s[i+1]) {
				flag++;
			}
			if (flag==2) {
				k--;
				flag=0;
				ans+=2;
			}
			if(flag==1&&i==n-2){
				ans++;
			}
		}
		if(s[i]==s[i+1]){
			ans++;
		}
	}
	cout<<ans<<endl;
}
