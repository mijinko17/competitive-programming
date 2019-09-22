#include <bits/stdc++.h>
using namespace std;

int gcd(long long int m,long long int n){
	m=abs(m);
	n=abs(n);
	if(m*n==0){
		return max(m,n);
	}else {
		return gcd(min(m,n),max(m,n)%min(m,n));
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	vector<int> l(n),r(n);
	l[0]=0;
	r[n-1]=0;
	for (int i = 0; i < n-1; i++) {
		l[i+1]=gcd(l[i],a[i]);
		r[n-i-2]=gcd(r[n-i-1],a[n-i-1]);
	}
	int ans=0;
	for (int i = 0; i < n; i++) {
		ans=max(ans,gcd(l[i],r[i]));
	}
	cout<<ans<<endl;
}
