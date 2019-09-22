#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long int ans=0;
	cin>>n;
	vector<int> a(n+1);
	vector<int> b(n);
	for (int i = 0; i < n+1; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
		cin>>b[i];
	}
	for (int i = 0; i < n; i++) {
		ans+=min(b[i],a[i]);
		b[i]-=min(b[i],a[i]);
		ans+=min(b[i],a[i+1]);
		a[i+1]-=min(b[i],a[i+1]);
	}
	cout<<ans<<endl;
}
