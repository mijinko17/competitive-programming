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
	long long int a,b,c,d;
	long long int cd;
	long long int divc,divd,divcd;
	long long int ans;
	cin>>a>>b>>c>>d;
	cd=c*d/gcd(c,d);
	divc=b/c-(a-1)/c;
	divd=b/d-(a-1)/d;
	divcd=b/cd-(a-1)/cd;
	ans=(b-a+1)-(divc+divd-divcd);
	cout<<ans<<endl;
}
