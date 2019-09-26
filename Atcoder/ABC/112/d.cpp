#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,m;
	cin>>n>>m;
	long long int ans=0;
	for (int i = m/n; i >=1; i--) {
		if (m%i==0) {
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
}
