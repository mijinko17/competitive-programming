#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int n,a,b;
	cin>>n>>a>>b;
	vector<long long int> x(n);
	for (int i = 0; i < n; i++) {
		cin>>x[i];
	}
	long long int ans=0;
	for (int i = 0; i < n-1; i++) {
		ans+=min((x[i+1]-x[i])*a,b);
	}
	cout<<ans<<endl;
}
